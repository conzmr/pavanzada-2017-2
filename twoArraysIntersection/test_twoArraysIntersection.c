#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "twoArraysIntersection.h"

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

static char * exampleTest() {
  int nums1Size = 4;
  int nums2Size = 2;
  int n1[4] = {1, 2, 2, 1};
  int n2[2] = {2, 2};
  int *nums1 = (int *) malloc(nums1Size * sizeof( int ));
  int *nums2 = (int *) malloc(nums2Size * sizeof( int ));
  for(int i=0;i<nums1Size;i++){
    nums1[i] = n1[i];
  }
  for(int j=0;j<nums2Size;j++){
    nums2[j] = n2[j];
  }
  int returnSize = 0;
  int *array = intersection(nums1 , nums1Size , nums2 , nums2Size, &returnSize);
  muAssert("error, returnSize must be 1", returnSize == 1);
  return 0;
}

static char * emptyIntersectionTest() {
  int nums1Size = 10;
  int nums2Size = 8;
  int n1[10] = {100, 54, 3, 532, 1,35,7,877,8,1};
  int n2[8] = {23,4,6,234,12,47,76,8653};
  int *nums1 = (int *) malloc(nums1Size * sizeof( int ));
  int *nums2 = (int *) malloc(nums2Size * sizeof( int ));
  for(int i=0;i<nums1Size;i++){
    nums1[i] = n1[i];
  }
  for(int j=0;j<nums2Size;j++){
    nums2[j] = n2[j];
  }
  int returnSize = 0;
  int *array = intersection(nums1 , nums1Size , nums2 , nums2Size, &returnSize);
  muAssert("error, returnSize must be 0", returnSize == 0);
  return 0;
}

static char * newNumbersTest() {
  int nums1Size = 10;
  int nums2Size = 8;
  int n1[10] = {100, 54, 3,47,76,8653,7,877,8,1};
  int n2[8] = {23,4,6,234,12,47,76,8653};
  int *nums1 = (int *) malloc(nums1Size * sizeof( int ));
  int *nums2 = (int *) malloc(nums2Size * sizeof( int ));
  for(int i=0;i<nums1Size;i++){
    nums1[i] = n1[i];
  }
  for(int j=0;j<nums2Size;j++){
    nums2[j] = n2[j];
  }
  int returnSize = 0;
  int *array = intersection(nums1 , nums1Size , nums2 , nums2Size, &returnSize);
  muAssert("error, returnSize must be 1", returnSize == 3);
  return 0;
}

static char * allTests() {
  muRunTest(exampleTest);
  muRunTest(emptyIntersectionTest);
  muRunTest(newNumbersTest);
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
