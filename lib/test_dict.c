#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "dict.h"

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

static char *testInitDictionary() {
  unsigned int size = 4;
  int errorCode;
  Dict *myDictionary = initDictionary(size, &errorCode); //pongo un & para pasar la dirección y ahí voy a escribir el error
  muAssert("myDictionary must be different than null", myDictionary != NULL);
  muAssert("myDictionary size must be 4", myDictionary->size == 4);
  muAssert("myDictionary errorCode must be 0", errorCode == 0);
  return 0;
}

// static char *testUpsertDictionary() {
//   unsigned int size = 1;
//   int errorCode;
//   Dict *myDictionary = initDictionary(size, &errorCode);
//   int value = 1;
//   upsertDictionary(myDictionary, "uno", (void *)&value, &errorCode);
//   void *result = getDictionary(myDictionary, "uno", &errorCode);
//
//   muAssert("myDictionary errorCode must be 0", errorCode == 0);
//   muAssert("result must be equal to value", *((int *)result == value); //Value is a pointer to anything, but I know that It is a pointer to int
//   return 0;
// }
//
// static char *testGetDictionary() {
//   unsigned int size = 1
//   int errorCode;
//   Dict *myDictionary = initDictionary(size, &errorCode); //pongo un & para pasar la dirección y ahí voy a escribir el error
//   muAssert("myDictionary must be different than null", myDictionary != NULL);
//   muAssert("myDictionary size must be 4", myDictionary->size == 4);
//   muAssert("myDictionary errorCode must be 0", errorCode == 0);
//   return 0;
// }

static char *testUpsertDictionary()
{
  unsigned int size = 1;
  int errorCode;
  Dict *myDictionary = initDictionary(size, &errorCode);
  int value = 1;
  upsertDictionary(myDictionary, "uno", (void *)&value, sizeof(int), &errorCode);

  muAssert("myDictionary errorCode must be 0", errorCode == 0);
  muAssert("myDictionary errorCode must be 0", strcmp(myDictionary->elements[0].key, "uno") == 0);
  muAssert("myDictionary errorCode must be 0", *((int *)myDictionary->elements[0].value) == value);
  return 0;
}


static char *testGetDictionary()
{
  unsigned int size = 1;
  int errorCode;
  Dict *myDictionary = initDictionary(size, &errorCode);
  int value = 1;
  upsertDictionary(myDictionary, "uno", (void *)&value,sizeof(int), &errorCode);
  void *result = getDictionary(myDictionary, "uno", sizeof(int), &errorCode);
  value = 27;
  muAssert("myDictionary errorCode must be 0", errorCode == 0);
  printf("%d\n", *((int *)result));
  muAssert("result must be equal to value", *((int *)result) == 1);
  return 0;
}


static char *allTests() {
  muRunTest(testInitDictionary);
  muRunTest(testUpsertDictionary);
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
