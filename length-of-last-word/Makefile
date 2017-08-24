CC=gcc
CFLAGS=-I.
DEPS = length-of-last-word.h
OBJ = length-of-last-word.o length-of-last-word-main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

length-of-last-word.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o *.exe
