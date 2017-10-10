LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c islandPerimeter.c
	 gcc -c main.c
	 gcc -o islandPerimeter.exe islandPerimeter.o main.o $(LIB)

test_islandPerimeter: clean
	 gcc -c islandPerimeter.c
	 gcc -c test_islandPerimeter.c
	 gcc -o test_islandPerimeter.exe islandPerimeter.o test_islandPerimeter.o
	 ./test_islandPerimeter.exe

test:	 test_islandPerimeter

clean:
	 rm *.out *.o *.exe || exit 0

islandPerimeter: clean
	 gcc -c islandPerimeter.c
	 gcc -c main.c
	 gcc -o islandPerimeter.exe islandPerimeter.o main.o $(LIB)

run: islandPerimeter
	 ./islandPerimeter.exe

runtest: islandPerimeter
	 ./integrationtest.tcl ./islandPerimeter.exe

