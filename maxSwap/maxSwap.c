#include <stdlib.h>
#include <stdio.h>
#include "maxSwap.h"

/***********************
* maximumSwap
* Given a non-negative integer, you could swap two digits at most once to get
* the maximum valued number.
* @param:
* num: non-negative integer
* @return:
* int: maximum valued number
*/
int maximumSwap(int num) {
    if(num<0)
    {
      return -1;
    }
    int maxDigitIndex = 0;
    int length = snprintf( NULL, 0, "%d", num );
    char* str = malloc( length + 1 );
    snprintf( str, length + 1, "%d", num );
    for (int i = 0; i < length - 1; i++)
    {
      for(int j = i + 1; j < length; j++)
      {
        if(str[j]>str[i] && str[j]>str[maxDigitIndex])
        {
          maxDigitIndex = j;
        }
      }
      if(maxDigitIndex!=0){
        char temp = str[maxDigitIndex];
        str[maxDigitIndex] = str[i];
        str[i] = temp;
        int maxSwap = atoi(str);
        return maxSwap;
      }
    }
    free(str);
    return num;
}
