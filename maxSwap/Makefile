all:
	 gcc -c maxSwap.c
	 gcc -c main.c
	 gcc -o main maxSwap.o main.o

test_maxSwap: clean
	 gcc -c maxSwap.c
	 gcc -c test_maxSwap.c
	 gcc -o test_maxSwap.exe maxSwap.o test_maxSwap.o
	 ./test_maxSwap.exe

test:	 test_maxSwap

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c maxSwap.c
	 gcc -c main.c
	 gcc -o main.exe maxSwap.o main.o
	 ./main
