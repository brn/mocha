SUBDIRS = src

mocha:
	cd src && bison -dv grammar.yy && cd ../
	./build

parser:
	cd src && bison -r state -dv -o grammar/grammar.tab.cc grammar/grammar.yy && cd ../

core :
	./build