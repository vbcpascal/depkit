%option namespace="depkit::yy" lex=yylex
%option bison-complete
%option bison-cc-namespace=depkit::yy
%option bison-cc-parser=Parser

%top {
#include "parser.h"

using namesapce depkit;
using namesapce depkit::yy;

#define TOKEN(t) (Parser::make_##t((int)Parser::token::t))
extern int yylex();
%}
		
ws				[ \t\n\r]+
comment_line	\/\/.*?\n
comment_block	\/\*.*?\*\/
comment			{comment_line}|{comment_block}
name			[a-zA-Z_][a-zA-Z0-9_]*
fpnum			[-+]?[0-9]+\.[0-9]*

%%

"."				return TOKEN(S_DOT);
","				return TOKEN(S_COMMA);
":"				return TOKEN(S_COLON);
";"				return TOKEN(S_SEMI);
"("				return TOKEN(S_LPR);
")"				return TOKEN(S_RPR);
"["				return TOKEN(S_LSR);
"]"				return TOKEN(S_RSR);
"{"				return TOKEN(S_LBR);
"}"				return TOKEN(S_RBR);
"="				return TOKEN(S_ASSIGN);
"=="			return TOKEN(S_EQ);
"!="			return TOKEN(S_NE);
">="			return TOKEN(S_GE);
"<="			return TOKEN(S_LE);
">"				return TOKEN(S_GT);
"<"				return TOKEN(S_LT);
"&&"			return TOKEN(S_AND);
"||"			return TOKEN(S_OR);
"!"				return TOKEN(S_NOT);
"in"			return TOKEN(K_IN);
"not in"		return TOKEN(K_NIN);
"if"			return TOKEN(K_IF);
"else"			return TOKEN(K_ELSE);
"require"		return TOKEN(K_REQ);
"version"		return TOKEN(K_V);
"features"		return TOKEN(K_F);
"backends"		return TOKEN(K_B);

{ws}			; /* skip */
{comment}		; /* skip */
{name}			return Parser::make_C_IDENTIFIER(str());
{fpnum}			return Parser::make_C_DOUBLE(atof(text()));

.				ERROR("Unknown token: %s", text());

%%
