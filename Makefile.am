SUBDIRS = src

parser:
	bison -dv src/grammar.yy
	mv grammar.tab.cc src
	mv stack.hh src
	mv grammar.tab.hh src
	mv position.hh src
	make
