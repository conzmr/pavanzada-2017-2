#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "qSort.h"

typedef struct s{
  char *name;
  int matricula;
} Student;

/* Add function signatures here */
int cmpNames(void *element1, void const *element2){ //Quick sort the devuelve dos direcciones
  Student *student1 = (Student *) element1;
  Student *student2 = (Student *) element2;
  return strcmp(student1->name, student2->name);
}

int cmpMatriculas(void *element1, void const *element2){ //Quick sort the devuelve dos direcciones
  Student *student1 = (Student *) element1;
  Student *student2 = (Student *) element2;
  return  student1->name - student2->name;
}

int main(int argc, char **argv) {
  char order[20];
  Student group[3];
  group[0].name = strdup("Juanito");
  group[0].matricula = 17;

  group[1].name = strdup("Pedro");
  group[1].matricula = 4;

  group[2].name = strdup("Mariana");
  group[2].matricula = 2;

  printf("Give me the order: \n" );
  scanf("%s", order);

  if(!strcmp(order,"name")){
    qsort(group,3,sizeof(Student),cmpNames); //en stdlib
  }

  if(!strcmp(order,"matricula")){
    qsort(group,3,sizeof(Student),cmpMatriculas); //en stdlib
  }


  for(int i = 0; i<3; i++){
    printf("Student %s %d \n", group[i].name, group[i].matricula);

  }

  return 0;

}
