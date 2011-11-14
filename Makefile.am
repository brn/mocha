SUBDIRS = src

mocha:
	cd src && bison -dv grammar.yy && cd ../
	./build

parser:
	cd src && bison -r state -dv grammar.yy && cd ../

core :
	./build