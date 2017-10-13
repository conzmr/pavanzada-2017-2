#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "qSort.h"

#define MAX_LENGTH_ORDER 20
#define STUDENTS_LENGTH 3

typedef struct s{
  char *name;
  int matricula;
} Student;


/* Add function signatures here */
int cmpStudent(void const *element1, void const *element2, int attribute){ //Quick sort the devuelve dos direcciones
  Student *student1 = (Student *) element1;
  Student *student2 = (Student *) element2;
  switch (attribute) {
    case 0: //name
      return strcmp(student1->name, student2->name);
    case 1: //matricula
      return  student1->matricula - student2->matricula;
  }
}

int cmpNames(void const *element1, void const *element2){ //Quick sort the devuelve dos direcciones
  return cmpStudent(element1, element2,0);
}

int cmpMatriculas(void const *element1, void const *element2){ //Quick sort the devuelve dos direcciones
  return cmpStudent(element1, element2,1);
}

int main(int argc, char **argv) {
  Student group[STUDENTS_LENGTH];
	Student key;
	Student * foundStudent;
	char order[MAX_LENGTH_ORDER];
  int neededStudent;


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

  printf("Which is the id?: ");
  scanf("%d\n", &neededStudent );
  key.matricula = neededStudent;

  foundStudent = bsearch(&key, group, STUDENTS_LENGTH, sizeof(Student), cmpMatriculas);
  if(foundStudent != NULL){
    printf("Student %s %d \n", foundStudent->name, foundStudent->matricula);
  }else{
    printf("Student not found with id %d", neededStudent );
  }

  return 0;

}
