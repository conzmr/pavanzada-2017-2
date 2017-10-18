LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c twoArraysIntersection.c
	 gcc -c main.c
	 gcc -o twoArraysIntersection.exe twoArraysIntersection.o main.o $(LIB)

test_twoArraysIntersection: clean
	 gcc -c twoArraysIntersection.c
	 gcc -c test_twoArraysIntersection.c
	 gcc -o test_twoArraysIntersection.exe twoArraysIntersection.o test_twoArraysIntersection.o
	 ./test_twoArraysIntersection.exe

test:	 test_twoArraysIntersection

clean:
	 rm *.out *.o *.exe || exit 0

twoArraysIntersection: clean
	 gcc -c twoArraysIntersection.c
	 gcc -c main.c
	 gcc -o twoArraysIntersection.exe twoArraysIntersection.o main.o $(LIB)

run: twoArraysIntersection
	 ./twoArraysIntersection.exe

runtest: twoArraysIntersection
	 ./integrationtest.tcl ./twoArraysIntersection.exe

