all:
	 gcc -c ransom-note.c
	 gcc -c main.c
	 gcc -o main ransom-note.o main.o

test_ransom-note: clean
	 gcc -c ransom-note.c
	 gcc -c test_ransom-note.c
	 gcc -o test_ransom-note.exe ransom-note.o test_ransom-note.o
	 ./test_ransom-note.exe

test:	 test_ransom-note

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c ransom-note.c
	 gcc -c main.c
	 gcc -o main.exe ransom-note.o main.o
	 ./main
