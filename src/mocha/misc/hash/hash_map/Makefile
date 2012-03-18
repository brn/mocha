CC = g++
FLAGS = -g -Wall -O3 -D__STDC_LIMIT_MACROS -DHAVE_CONFIG_H -I./../../../
TARGET = test

all : $(TARGET)

.SUFFIXES : .cc

.cc.o : %.o:%.cc
	$(CC) -c $(FLAGS) $<

profiler.o : ../../profiler.h ../../profiler.cc
	$(CC) -c $(FLAGS) $^

test.o : hash_map.h test.cc
	$(CC) -c $(FLAGS) $^

test : test.o profiler.o
	$(CC) -o test test.o profiler.o

clean:
	@rm -f *.o  $(TARGET)
	@rm -f *~ core *.gcov *.da *.bb *.bbg *.log *.aux gmon.out logfile *.gch