all:
	 gcc -c keyboardRow.c
	 gcc -c main.c
	 gcc -o main keyboardRow.o main.o

test_keyboardRow: clean
	 gcc -c keyboardRow.c
	 gcc -c test_keyboardRow.c
	 gcc -o test_keyboardRow.exe keyboardRow.o test_keyboardRow.o
	 ./test_keyboardRow.exe

test:	 test_keyboardRow

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c keyboardRow.c
	 gcc -c main.c
	 gcc -o main.exe keyboardRow.o main.o
	 ./main
