all: bison lex

bison:
	bison --defines=include/parser.hpp --output=lib/parser/parser.cpp -Wempty-rule -v lib/parser/parser.yy && \
	mv lib/parser/location.hh include/

lex:
	reflex --header-file=include/lex.hpp --outfile=lib/parser/lex.cpp lib/parser/lex.l

clean:
	rm include/parser.hpp include/lex.hpp include/location.hh lib/parser/parser.cpp lib/parser/lex.cpp lib/parser/parser.output