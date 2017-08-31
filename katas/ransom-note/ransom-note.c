#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ransom-note.h"

int canConstruct(char* ransomNote, char* magazine) {
  if(strcmp(magazine, ransomNote)==0)
  {
    return 1;
  }
  char * magazineCopy = strdup(magazine);
  while(ransomNote[0] != '\0')
  {
    if(ransomNote[0]!=' ')
    {
      char* var = strchr(magazineCopy, ransomNote[0]);
      if(!var)
      {
        free(magazineCopy);
        return 0;
      }
      *var = ' ';
    }
    ransomNote++;
  }
  free(magazineCopy);
  return 1;
}
