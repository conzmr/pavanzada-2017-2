LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c qSort.c
	 gcc -c main.c
	 gcc -o qSort.exe qSort.o main.o $(LIB)

test_qSort: clean
	 gcc -c qSort.c
	 gcc -c test_qSort.c
	 gcc -o test_qSort.exe qSort.o test_qSort.o
	 ./test_qSort.exe

test:	 test_qSort

clean:
	 rm *.out *.o *.exe || exit 0

qSort: clean
	 gcc -c qSort.c
	 gcc -c main.c
	 gcc -o qSort.exe qSort.o main.o $(LIB)

run: qSort
	 ./qSort.exe

runtest: qSort
	 ./integrationtest.tcl ./qSort.exe

