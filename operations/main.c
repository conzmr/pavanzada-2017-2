#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"
//defines no llevan ;
//se sustituyen en precompilador
// #define DEBUG 1;
#define MAX_LENGTH 10 //Tamaño máximo de mis operaciones
#define printDebug(msg) do { char *value = getenv("OPER_DEBUG"); if ( !strcmp(value,"t") ) printf("%s", msg);} while(0)

char *operationNames_ES[] = {"suma", "resta"};
char *operationNames_EN[] = {"add", "subtract"};
char *messages_ES[] = {"¿Cuál es la operación?"};
char *messages_EN[] = {"Which is the operation?"};

//if(DEBUG) printf(msg); Para no tener que compilar para switchear
//NO DEBE HABER NUNCA NÚMEROS MÁGICOS
//SIEMPRE DEJARLO EN VARIABLES


int addition(int a, int b)
{
  return a+b;
}

int subtraction(int a, int b)
{
  return a-b;
}

int main(int argc, char **argv) {
  /* Start your code here */
  char *operationName;
  int operator1, operator2;
  int (*operation)(int,int); // para asignar funciones -> tipo funcion que regresa entero y 2 enteros de parámetros
  char message[200];
  char **operationNames;
  char **messages;
  char *lang;

  lang = getenv("OPER_LANG");
  if((lang!= NULL) && !strcmp(lang, "ES")){
    operationNames = operationNames_ES;
    messages = messages_ES;
  }else{
    operationNames = operationNames_EN;
    messages = messages_EN;
  }
  operationName = malloc(sizeof(char)*MAX_LENGTH);

  printf("%s",messages[0]);
  scanf("%s", operationName); //ya es una dirección
  scanf("%d", &operator1); //requiero amperson para que lo pueda manipular porque no es un puntero, una dirección
  scanf("%d", &operator2);
  sprintf(message, "operationName = %s \n", operationName);
  printDebug(message);
  sprintf(message, "operator1 = %d \n", operator1);
  printDebug(message);
  sprintf(message, "operator2 = %d \n", operator2);
  printDebug(message);


  if(!strcmp(operationName, operationNames[0]))
  {
    operation = addition;
  }
  if(!strcmp(operationName,operationNames[1]))
  {
    operation = subtraction;
  }
  int result = operation(operator1, operator2);
  printf("%d\n", result);
  printf("Resultado de %s es: %d\n", operationName, result); //en lugar de la operación pongo operation suma | resta
  return 0;
}

//export OPER_DEBUG=t
//export OPER_LANG=ES
