#include <stdlib.h>
#include <stdio.h>
#include "dict.h"
//Everything that makes my code more understandable is welcome
//change dictElement by elements

Dict * initDictionary(unsigned int size, int *errorCode)
{ //Won't be able to give negative num
//with *errorCode I will have the content, I will modify the error. Without * I will modify the direction
  Dict *newDict;
  newDict = (Dict *)calloc(1, sizeof(Dict));//Calloc may find no memory
  if(newDict == NULL)
  {
    *errorCode = 100; //Now I know where it fails.
    return NULL;
  }
  newDict->size= size;
  newDict->elements = (DictElement *)calloc(size, sizeof(DictElement));
  if(newDict->elements == NULL)
  {
    *errorCode = 200; //with the asterisc before name I am modifying content.
    return NULL;
  }
  *errorCode = 0;
  return newDict;
}

//Difference between calloc and malloc
// Calloc cleans, put everything in 0's
// Malloc is more efficient, and I use it when
// I do not matter what it has, I will change it

/* hash: form hash value for string s */
static unsigned hash(char *s, unsigned int size) //static made my method private, is only available on this file
{
  unsigned hashval;
  for(hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval; //I put 31 because this way is less the probably of collision
  return hashval % size;
}

void upsertDictionary(Dict *dictionary, char *key, void *value, int *errorCode)
{
  if(dictionary == NULL)
  {
      *errorCode = 100; //For convencion on this library, 100 is for NULL.
      return;
  }
  if(key == NULL)
  {
      *errorCode = 100;
      return;
  }
  if(value== NULL)
  {
      *errorCode = 100;
      return;
  }
  int index = hash(key, dictionary->size);
  dictionary->elements[index].key = key;
  dictionary->elements[index].value = value;
  *errorCode = 0;
}


//Functions must do ONLY ONE THING, and do that very well
