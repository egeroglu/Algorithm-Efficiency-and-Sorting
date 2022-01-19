



CPP_FLAGS='-std=c++11'
LDLIBS=-lm
hw1: main.o sorting.o
	g++ ${CPP_FLAGS} main.o sorting.o -o hw1
main.o: main.cpp
	g++ ${CPP_FLAGS} -c main.cpp
sorting.o: sorting.cpp sorting.h
	g++ ${CPP_FLAGS} -c sorting.cpp
clean:
	rm *.o hw1
