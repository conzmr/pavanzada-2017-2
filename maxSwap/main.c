#include <stdlib.h>
#include <stdio.h>
#include "maxSwap.h"

int main(int argc, char **argv) {
  int num = 35109973;
  int maxSwap = maximumSwap(num);
  if(maxSwap!=-1)
  {
    printf("Maximum swap for %i is %i\n",num, maxSwap );
  }
  else
  {
    printf("Number to swap must be positive\n");
  }
  return 0;
}
