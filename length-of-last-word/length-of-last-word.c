#include <stdlib.h>
#include "length-of-last-word.h"

int getLength(char* string, int size)
{
    int firstChar = 0;
    int count = 0;
    for(int i = size-2; i > 0; i--) {
        if(string[i] != ' ' && firstChar == 0) {
            firstChar = i;
        }
        if(string[i] == ' ' && firstChar != 0) {
            return count;
        }
        else if(string[i] != ' ' && firstChar != 0){
            count++;
        }
    }
    return 0;
}
