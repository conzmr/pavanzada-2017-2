#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void upsertDictionary(Dict *dictionary, char *key, void *value, int size, int *errorCode)
{
    if (dictionary == NULL)
    {
        *errorCode = 100;
        return;
    }
    if (dictionary->elements == NULL)
    {
        *errorCode = 100;
        return;
    }
    if (key == NULL)
    {
        *errorCode = 100;
        return;
    }
    if (value == NULL)
    {
        *errorCode = 100;
        return;
    }
    if (size <= 0)
    {
        *errorCode = 100;
        return;
    }

    int index = hash(key, dictionary->size);
    dictionary->elements[index].key = key;
    dictionary->elements[index].value = malloc(size);
    if(dictionary->elements[index].value == NULL){
        *errorCode = 100;
        return;
    }
    memcpy(dictionary->elements[index].value,value,size);
    *errorCode = 0;
}


void * getDictionary(Dict *dictionary,char *key,int size, int *errorCode) {
    if (dictionary == NULL)
    {
        *errorCode = 100;//For convencion on this library, 100 is for NULL.
        return NULL;
    }
    if (dictionary->elements == NULL)
    {
        *errorCode = 100;
        return NULL;;
    }
    if (key == NULL)
    {
        *errorCode = 100;
        return NULL;
    }
    if (size <= 0)
    {
        *errorCode = 100;
        return NULL;
    }

    int index = hash(key, dictionary->size);
    void *result = malloc(size);
    if(result == NULL){
        *errorCode = 100;
        return NULL;
    }
    memcpy(result,dictionary->elements[index].value,size);
    return result;
}


//Functions must do ONLY ONE THING, and do that very well


//necesito void * y un size ; es tedioso pasar el tamaño pero lo hace super flexible


//COMANDOS


//gcc -c -o dict.o dict.c
//Para embeded systems de manera cerrada, no pueden tener el código fuente
// cd testlib

//ls

//cp ../lib/dict.o .
//cp ../lib/dict.h .


//basta con copiar el punto o para poder utilizar la librería


//para compilarlo es gcc -g students.exe main.c dict.o
