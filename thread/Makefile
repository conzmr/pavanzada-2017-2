LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c thread.c
	 gcc -c main.c
	 gcc -o thread.exe thread.o main.o $(LIB)

test_thread: clean
	 gcc -c thread.c
	 gcc -c test_thread.c
	 gcc -o test_thread.exe thread.o test_thread.o
	 ./test_thread.exe

test:	 test_thread

clean:
	 rm *.out *.o *.exe || exit 0

thread: clean
	 gcc -c thread.c
	 gcc -c main.c
	 gcc -o thread.exe thread.o main.o $(LIB)

run: thread
	 ./thread.exe

runtest: thread
	 ./integrationtest.tcl ./thread.exe

