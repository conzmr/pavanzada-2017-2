LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c chat-client.c
	 gcc -c main.c
	 gcc -o chat-client.exe chat-client.o main.o $(LIB)

test_chat-client: clean
	 gcc -c chat-client.c
	 gcc -c test_chat-client.c
	 gcc -o test_chat-client.exe chat-client.o test_chat-client.o
	 ./test_chat-client.exe

test:	 test_chat-client

clean:
	 rm *.out *.o *.exe || exit 0

chat-client: clean
	 gcc -c chat-client.c
	 gcc -c main.c
	 gcc -o chat-client.exe chat-client.o main.o $(LIB)

run: chat-client
	 ./chat-client.exe

runtest: chat-client
	 ./integrationtest.tcl ./chat-client.exe

