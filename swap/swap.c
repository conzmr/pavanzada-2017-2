#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "swap.h"

//me permite intercambiar 2 contentidos
void swap(void *a, void *b, int size){
  char *buffer;
  buffer = (char *) malloc(sizeof(char)*size);
  memcpy(buffer, a, size);
  memcpy(a, b, size); //orden origen, destino
  memcpy(b, buffer, size);
  free(buffer);
}
