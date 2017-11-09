#include <stdlib.h>
#include <stdio.h>
#include "fizzBuzz.h"

/* Add function signatures here */

int main(int argc, char **argv) {
  int * size = (int *) malloc(sizeof(int));
   char ** result = fizzBuzz(15, size);
   int i = 0;
   for (i = 0; i < *size; i++) {
       printf("%s\n", result[i]);
   }
  return 0;
}
