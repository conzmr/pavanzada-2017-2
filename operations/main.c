#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"
//defines no llevan ;
//se sustituyen en precompilador
// #define DEBUG 1;
#define MAX_LENGTH 10 //Tamaño máximo de mis operaciones
#define printDebug(msg) do { char *value = getenv("OPER_DEBUG"); if ( !strcmp(value,"t") ) printf("%s", msg);} while(0)

//if(DEBUG) printf(msg); Para no tener que compilar para switchear
//NO DEBE HABER NUNCA NÚMEROS MÁGICOS
//SIEMPRE DEJARLO EN VARIABLES


int sum(int a, int b)
{
  return a+b;
}

int substraction(int a, int b)
{
  return a-b;
}

int main(int argc, char **argv) {
  /* Start your code here */
  char *operationName;
  int operator1, operator2;
  int (*operation)(int,int); // para asignar funciones -> tipo funcion que regresa entero y 2 enteros de parámetros
  char message[200];
  operationName = malloc(sizeof(char)*MAX_LENGTH);

  printf("¿Cuál es la operación?\n");
  scanf("%s", operationName); //ya es una dirección
  scanf("%d", &operator1); //requiero amperson para que lo pueda manipular porque no es un puntero, una dirección
  scanf("%d", &operator2);
  sprintf(message, "operationName = %s \n", operationName);
  printDebug(message);
  sprintf(message, "operator1 = %d \n", operator1);
  printDebug(message);
  sprintf(message, "operator2 = %d \n", operator2);
  printDebug(message);
  printf("9\n");


  if(!strcmp(operationName, "suma"))
  {
    operation = sum;
  }
  if(!strcmp(operationName, "resta"))
  {
    operation = substraction;
  }
  printf("Resultado de %s es: %d\n", operationName, operation(operator1, operator2)); //en lugar de la operación pongo operation suma | resta
  return 0;
}

//export OPER_DEBUG=t
