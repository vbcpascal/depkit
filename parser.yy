%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.4"
%language "c++"

%define api.namespace {depkit::yy}
%define api.parser.class {Parser}
%define api.value.type variant
%define api.token.constructor
%define parse.assert
%defines

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
%token <std::string> C_IDENTIFIER
%token <double>	C_DOUBLE
%token <int>	S_DOT S_COMMA S_COLON S_SEMI S_LPR S_RPR S_LSR S_RSR S_LBR S_RBR 
%token <int>	S_ASSIGN S_EQ S_NE S_GE S_LE S_GT S_LT S_AND S_OR S_NOT 
%token <int>	K_IN K_NIN K_IF K_ELSE K_REQ K_V K_F K_B

/* types */

%type <std::string>		name str
%type <TermsPtr>		terms
%type <std::list<DefinitionPtr>>	definitions
%type <std::list<DependencyPtr>>    dependencies
%type <std::list<RequirementPtr>>	requirements
%type <IdentificationPtr>			package_identification
%type <PropertyListPtr>				property_list
%type <std::list<Version>>			version_list
%type <std::list<Feature>>			feature_list
%type <std::list<Backend>>			backend_list
%type <std::list<std::string>>		tok_list
%type <DefinitionPtr>				package_definition
%type <DependencyPtr>				package_dependency dep_body
%type <std::list<PropExprPtr>>		require_list
%type <PropExprPtr>					

%start terms

%%

terms
	: definitions dependencies requirements		{ $$ = std::make_shared<Terms>($1, $2, $3);
	;

definitions
	: definitions package_definition			{ $1.push_back($2); $$ = $1; }
	| %empty									{ $$ = std::list<DefinitonPtr>(); }
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
	: version_list S_SEMI feature_list S_SEMI backend_list
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
	: tok_list S_COMMA str						{ $1.push_back($3); $$ = $1; }
	| %empty									{ $$ = std::list<std::string>(); }
	;

package_definition
	: package_identification S_ASSIGN S_LPR S_RPR	{ $$ = std::make_shared<Definition>($1); }
	;

package_dependency
	: package_identification S_COLON dep_body	{ $3->identification_ = $1; $$ = $3; }
	;

dep_body
	: S_LBR require_list depend_list S_RBR		{ $$ = std::make_shared<Dependency>($2, $3); }
	;

require_list
	: require_list require_clause				{ $1.push_back($2); $$ = $1; }
	| %empty									{ $$ = std::list<PropExprPtr>(); }
	;

require_clause
	: K_REQ S_LPR property_expr S_RPR S_SEMI
	;

depend_list
	: depend_clause depend_list
	| %empty
	;

depend_clause
	: package_expr
	| if_package
	| if_else_package
	;

if_package
	: K_IF property_expr S_LBR depend_clause S_RBR
	;

if_else_package
	: if_package K_ELSE S_LBR depend_clause S_RBR
	;

property_expr
	: prop_expr_or
	;

prop_expr_or
	: prop_expr_and
	| prop_expr_and S_OR prop_expr_or
	;

prop_expr_and
	: prop_expr_not
	| prop_expr_not S_AND prop_expr_and
	;

prop_expr_not
	: prop_expr_atom
	| S_NOT prop_expr_not
	;

prop_expr_atom
	: prop_name S_EQ str
	| prop_name S_NE str
	| prop_name S_LT str
	| prop_name S_GT str
	| prop_name S_LE str
	| prop_name S_GE str
	| str K_IN prop_name
	| str K_NIN prop_name
	;

	
package_expr
	: package_expr_or
	;

package_expr_or
	: package_expr_and
	| package_expr_and S_OR package_expr_or
	;

package_expr_and
	: package_expr_not
	| package_expr_not S_AND package_expr_and
	;

package_expr_not
	: package_expr_atom
	| S_NOT package_expr_not
	;

package_expr_atom
	: name
	| package_prop S_EQ str
	| package_prop S_NE str
	| package_prop S_LT str
	| package_prop S_GT str
	| package_prop S_LE str
	| package_prop S_GE str
	| str K_IN package_prop
	| str K_NIN package_prop
	;

package_prop
	: name S_DOT prop_name
	;

requirement
	: package_identification requirement
	| %empty
	;

name
	: C_IDENTIFIER
	;

str
	: C_IDENTIFIER
	;