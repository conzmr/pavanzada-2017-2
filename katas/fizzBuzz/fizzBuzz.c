#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fizzBuzz.h"

/**
  * fizzBuzz
  * Outputs the string representation of numbers from 1 to n.
  * For multiples of three, instead of the number, outputs 'Fizz', for multiples of
  * five, outputs 'Buzz', and for multiples of three and five outputs 'FizzBuzz'.
  * @param:
  *   n - Upper limit integer to represent the list.
  *   returnSize - Size of the returning characters array.
  * @return:
  *   char ** - List of all strings in series.
  *
  * Note: The returned array must be malloced, assume caller calls free().
**/
char** fizzBuzz(int n, int* returnSize) {
  char ** output = (char **) malloc(sizeof(char * ) * n);
  *returnSize = n;
  int numLength;
  for(int i = 1; i <= n; i++){
    if(i%5 == 0){
      if(i%3 == 0){
        output[i - 1] = (char *) malloc(sizeof(char) * 9);
        strcpy(output[i - 1], "FizzBuzz");
      }else{
        output[i - 1] = (char *) malloc(sizeof(char) * 5);
        strcpy(output[i - 1], "Buzz");
      }
    }
    else if(i%3 == 0){
      output[i - 1] = (char *) malloc(sizeof(char) * 5);
      strcpy(output[i - 1], "Fizz");
    }
    else{
      numLength = snprintf( NULL, 0, "%d", i );
      output[i - 1] = (char *) malloc(numLength+1);
      snprintf( output[i - 1], numLength + 1, "%d", i );
    }
  }
  return output;
}
