#include <stdio.h>
#include "length-of-last-word.h"

int main()
{
    char string[] = "Me gustan las zanahorias y las jícamas, pero más las zanahorias     ";
    int wordLength = getLength(string, sizeof(string));
    printf("String: \"%s\"\n Length of last word: %d\n", string, wordLength);

    return 0;
}
