#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"
#include "fizzBuzz.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

static char * testMultiplesOfThreeAndFive() {
  int * size = (int *) malloc(sizeof(int));
   char ** result = fizzBuzz(15, size);
   int i = 0;
   for (i = 0; i < *size; i++) {
       printf("%s\n", result[i]);
   }
  muAssert("error, Multiples of 3 and 5 must be 'FizzBuzz'", strcmp(result[14], "FizzBuzz")==0);
  return 0;
}

static char * testMultiplesOfThree() {
   int * size = (int *) malloc(sizeof(int));
   char ** result = fizzBuzz(25, size);
   int i = 0;
   for (i = 0; i < *size; i++) {
       printf("%s\n", result[i]);
   }
  muAssert("error, Multiples of 3 must be 'Fizz' ", strcmp(result[2], "Fizz")==0);
  return 0;
}

static char * testMultiplesOfFive() {
   int * size = (int *) malloc(sizeof(int));
   char ** result = fizzBuzz(319, size);
   int i = 0;
   for (i = 0; i < *size; i++) {
       printf("%s\n", result[i]);
   }
  muAssert("error, Multiples of 5 must be 'Buzz' ", strcmp(result[4], "Buzz")==0);
  return 0;
}

static char * allTests() {
  muRunTest(testMultiplesOfThreeAndFive);
  muRunTest(testMultiplesOfThree);
  muRunTest(testMultiplesOfFive);
  return 0;
}

int main(int argc, char **argv) {
  char *result = allTests();
  if (result != 0) {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
    printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
    printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", testsRun);
  return result != 0;
}
