#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"
#include "keyboardRow.h"

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

static char * testReturnSize() {
  int wordsSize = 4;
  int returnSize = 0;
  char *words[wordsSize];
  words[0] = "hello";
  words[1] = "alaska";
  words[2] = "pero";
  words[3] = "pedo";
  char **outputWords = findWords(&*words, wordsSize, &returnSize);
	muAssert("Error, returnSize must be == 2", returnSize == 2);
	return 0;
}

static char * testCapitalizedWords() {
  int wordsSize = 4;
  int returnSize = 0;
  char *words[wordsSize];
  words[0] = "Hello";
  words[1] = "Alaska";
  words[2] = "Pero";
  words[3] = "Pedo";
  char **outputWords = findWords(&*words, wordsSize, &returnSize);
	muAssert("Error, outputWords[0] must be == Alaska", outputWords[0][0] == 'A');
	return 0;
}

static char * testDifferentWords() {
  int wordsSize = 4;
  int returnSize = 0;
  char *words[wordsSize];
  words[0] = "mira";
  words[1] = "wow";
  words[2] = "perro";
  words[3] = "sala";
  char **outputWords = findWords(&*words, wordsSize, &returnSize);
	muAssert("Error, incorrect output", returnSize == 3 && outputWords[0][0] == 'w');
	return 0;
}


static char * allTests() {
  muRunTest(testReturnSize);
  muRunTest(testCapitalizedWords);
  muRunTest(testDifferentWords);
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
