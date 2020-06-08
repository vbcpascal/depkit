%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.4"
%language "c++"

%define api.namespace {depkit::yy}
%define api.parser.class {Parser}
%define api.value.type variant
%define api.token.constructor
%define parse.assert
%define parse.trace true
%define parse.error verbose
%defines

%locations

%code top {
#include <cstdio>
#include <map>
#include <vector>
}

%code requires {
#include "codegen.h"
using namespace depkit;

namespace depkit::yy{
	class Lexer;
}
}

%parse-param { depkit::yy::Lexer& lexer }

%code {
TermsPtr terms;

#include "lex.hpp"
#undef yylex
#define yylex lexer.yylex
}

/* tokens */

%token <std::string> C_IDENTIFIER C_DOUBLE
%token <int>	S_DOT S_COMMA S_COLON S_SEMI S_LPR S_RPR S_LSR S_RSR S_LBR S_RBR 
%token <int>	S_ASSIGN S_EQ S_NE S_GE S_LE S_GT S_LT S_AND S_OR S_NOT S_SEP
%token <int>	K_IN K_NIN K_IF K_ELSE K_REQ K_V K_F K_B

/* types */

%type <std::string>					name str prop_name
%type <TermsPtr>					terms
%type <std::list<DefinitionPtr>>	definitions
%type <std::list<DependencyPtr>>    dependencies
%type <std::list<RequirementPtr>>	requirements
%type <IdentificationPtr>			package_identification
%type <PropertyListPtr>				property_list			
%type <std::list<std::string>>		tok_list tok_list_nonempty version_list feature_list backend_list
%type <DefinitionPtr>				package_definition
%type <DependencyPtr>				package_dependency dep_body
%type <RequirementPtr>				requirement
%type <std::list<PropExprPtr>>		require_list
%type <std::list<PackageExprPtr>>	depend_list
%type <PropExprPtr>					require_clause property_expr prop_expr_or prop_expr_and prop_expr_not prop_expr_atom
%type <PackageExprPtr>				depend_clause if_package if_else_package package_expr package_expr_or package_expr_and package_expr_not package_expr_atom

%start terms

%%

terms
	: definitions S_SEP dependencies S_SEP requirements		{ terms = std::make_shared<Terms>($1, $3, $5); }
	;

definitions
	: definitions package_definition			{ $1.push_back($2); $$ = $1; }
	| %empty									{ $$ = std::list<DefinitionPtr>(); }
	;

dependencies
	: dependencies package_dependency			{ $1.push_back($2); $$ = $1; }	
	| %empty									{ $$ = std::list<DependencyPtr>(); }
	;

requirements
	: requirements requirement					{ $1.push_back($2); $$ = $1; }
	| %empty									{ $$ = std::list<RequirementPtr>(); }
	;

package_identification
	: name S_LSR property_list S_RSR			{ $$ = std::make_shared<Identification>($1, $3); }
	;

property_list
	: version_list S_SEMI feature_list S_SEMI backend_list S_SEMI 
												{ $$ = std::make_shared<PropertyList>($1, $3, $5); }
	;

version_list
	: K_V S_COLON S_LBR tok_list S_RBR			{ $$ = $4; }
	;

feature_list
	: K_F S_COLON S_LBR tok_list S_RBR			{ $$ = $4; }
	;

backend_list
	: K_B S_COLON S_LBR tok_list S_RBR			{ $$ = $4; }
	;

tok_list
	: tok_list_nonempty				{ $$ = $1; }
	| %empty									{ $$ = std::list<std::string>(); }
	;

tok_list_nonempty
	: tok_list S_COMMA str						{ $1.push_back($3); $$ = $1; }
	| str									{ $$ = std::list<std::string>(); $$.push_back($1); }
	;

package_definition
	: package_identification S_ASSIGN S_LPR S_RPR	{ $$ = std::make_shared<Definition>($1); }
	;

package_dependency
	: package_identification S_COLON dep_body	{ $3->identification_ = $1; $$ = $3; }
	| name S_COLON dep_body { $3->identification_ = std::make_shared<Identification>($1); $$ = $3; }
	;

dep_body
	: S_LBR require_list depend_list S_RBR		{ $$ = std::make_shared<Dependency>($2, $3); }
	;

require_list
	: require_list require_clause				{ $1.push_back($2); $$ = $1; }
	| %empty									{ $$ = std::list<PropExprPtr>(); }
	;

require_clause
	: K_REQ S_LPR property_expr S_RPR S_SEMI	{ $$ = $3; }
	;

depend_list
	: depend_list depend_clause					{ $1.push_back($2); $$ = $1; }
	| %empty									{ $$ = std::list<PackageExprPtr>(); }
	;

depend_clause
	: package_expr								{ $$ = $1; }
	| if_package								{ $$ = $1; }
	| if_else_package							{ $$ = $1; }
	;

if_package
	: K_IF property_expr S_LBR depend_clause S_RBR	{ $$ = std::make_shared<IfPackage>($2, $4); }
	;

if_else_package
	: K_IF property_expr S_LBR depend_clause S_RBR K_ELSE S_LBR depend_clause S_RBR
												{ $$ = std::make_shared<IfElsePackage>($2, $4, $8); }
	;

property_expr
	: prop_expr_or								{ $$ = $1; }
	;

prop_expr_or
	: prop_expr_and								{ $$ = $1; }
	| prop_expr_and S_OR prop_expr_or			{ $$ = std::make_shared<PropExprBinary>(BinaryType::OR, $1, $3); }
	;

prop_expr_and	
	: prop_expr_not								{ $$ = $1; }
	| prop_expr_not S_AND prop_expr_and			{ $$ = std::make_shared<PropExprBinary>(BinaryType::AND, $1, $3); }
	;

prop_expr_not
	: prop_expr_atom								{ $$ = $1; }
	| S_NOT prop_expr_not						{ $$ = std::make_shared<PropExprUnary>(UnaryType::NOT, $2); }
	;

prop_expr_atom
	: prop_name S_EQ str						{ $$ = std::make_shared<PropExprAtom>(AtomType::EQ, $1, $3); }
	| prop_name S_NE str						{ $$ = std::make_shared<PropExprAtom>(AtomType::NE, $1, $3); }
	| prop_name S_GT str						{ $$ = std::make_shared<PropExprAtom>(AtomType::GT, $1, $3); }
	| prop_name S_LT str						{ $$ = std::make_shared<PropExprAtom>(AtomType::LT, $1, $3); }
	| prop_name S_GE str						{ $$ = std::make_shared<PropExprAtom>(AtomType::GE, $1, $3); }
	| prop_name S_LE str						{ $$ = std::make_shared<PropExprAtom>(AtomType::LE, $1, $3); }
	| str K_IN prop_name						{ $$ = std::make_shared<PropExprAtom>(AtomType::IN, $3, $1); }
	| str K_NIN prop_name						{ $$ = std::make_shared<PropExprAtom>(AtomType::NIN, $3, $1); }
	;

package_expr
	: package_expr_or							{ $$ = $1; }
	;

package_expr_or
	: package_expr_and							{ $$ = $1; }
	| package_expr_and S_OR package_expr_or		{ $$ = std::make_shared<PackageExprBinary>(BinaryType::OR, $1, $3); }
	;

package_expr_and
	: package_expr_not							{ $$ = $1; }
	| package_expr_not S_AND package_expr_and	{ $$ = std::make_shared<PackageExprBinary>(BinaryType::AND, $1, $3); }
	;

package_expr_not
	: package_expr_atom							{ $$ = $1; }
	| S_NOT package_expr_not					{ $$ = std::make_shared<PackageExprUnary>(UnaryType::NOT, $2); }
	;

package_expr_atom
	: name										{ $$ = std::make_shared<PackageExprAtomWithName>($1); }
	| name S_DOT prop_name S_EQ str				{ $$ = std::make_shared<PackageExprAtomWithProp>(AtomType::EQ, $1, $3, $5); }
	| name S_DOT prop_name S_NE str				{ $$ = std::make_shared<PackageExprAtomWithProp>(AtomType::NE, $1, $3, $5); }
	| name S_DOT prop_name S_GT str				{ $$ = std::make_shared<PackageExprAtomWithProp>(AtomType::GT, $1, $3, $5); }
	| name S_DOT prop_name S_LT str				{ $$ = std::make_shared<PackageExprAtomWithProp>(AtomType::LT, $1, $3, $5); }
	| name S_DOT prop_name S_GE str				{ $$ = std::make_shared<PackageExprAtomWithProp>(AtomType::GE, $1, $3, $5); }
	| name S_DOT prop_name S_LE str				{ $$ = std::make_shared<PackageExprAtomWithProp>(AtomType::LE, $1, $3, $5); }
	| str K_IN name S_DOT prop_name				{ $$ = std::make_shared<PackageExprAtomWithProp>(AtomType::IN, $3, $5, $1); }
	| str K_NIN name S_DOT prop_name			{ $$ = std::make_shared<PackageExprAtomWithProp>(AtomType::NIN, $3, $5, $1); }
	;

requirement
	: package_identification					{ $$ = std::make_shared<Requirement>($1); }
	;

prop_name
	: K_V		{ $$ = "version"; }
	| K_F		{ $$ = "feature"; }
	| K_B		{ $$ = "backend"; }
	;

name
	: C_IDENTIFIER								{ $$ = $1; }
	;

str
	: C_IDENTIFIER								{ $$ = $1; }
	| C_DOUBLE										{ $$ = $1; }
	;

%%

void depkit::yy::Parser::error(const location& loc, const std::string& msg)
{
  std::cerr << loc << ": " << msg << std::endl;
  if (lexer.size() == 0)      // if token is unknown (no match)
    lexer.matcher().winput(); // skip character
}