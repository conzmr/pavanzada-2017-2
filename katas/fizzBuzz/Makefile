LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c fizzBuzz.c
	 gcc -c main.c
	 gcc -o fizzBuzz.exe fizzBuzz.o main.o $(LIB)

test_fizzBuzz: clean
	 gcc -c fizzBuzz.c
	 gcc -c test_fizzBuzz.c
	 gcc -o test_fizzBuzz.exe fizzBuzz.o test_fizzBuzz.o
	 ./test_fizzBuzz.exe

test:	 test_fizzBuzz

clean:
	 rm *.out *.o *.exe || exit 0

fizzBuzz: clean
	 gcc -c fizzBuzz.c
	 gcc -c main.c
	 gcc -o fizzBuzz.exe fizzBuzz.o main.o $(LIB)

run: fizzBuzz
	 ./fizzBuzz.exe

runtest: fizzBuzz
	 ./integrationtest.tcl ./fizzBuzz.exe

