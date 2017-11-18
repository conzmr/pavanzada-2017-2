LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c tcp.c
	 gcc -c main.c
	 gcc -o tcp.exe tcp.o main.o $(LIB)

test_tcp: clean
	 gcc -c tcp.c
	 gcc -c test_tcp.c
	 gcc -o test_tcp.exe tcp.o test_tcp.o
	 ./test_tcp.exe

test:	 test_tcp

clean:
	 rm *.out *.o *.exe || exit 0

tcp: clean
	 gcc -c tcp.c
	 gcc -c main.c
	 gcc -o tcp.exe tcp.o main.o $(LIB)

run: tcp
	 ./tcp.exe

runtest: tcp
	 ./integrationtest.tcl ./tcp.exe

