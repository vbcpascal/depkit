all: bison lex

bison:
	bison --defines=parser.hpp --output=parser.cpp -Wempty-rule -v parser.yy

lex:
	reflex --header-file=lex.hpp --outfile=lex.cpp lex.l
