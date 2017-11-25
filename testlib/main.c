
#include

/*Add function signatures here*/
typedef struct a {
  char *name;
  int semestre;
} Student;

int main(int argc, char **argv){
  Dict *students;
  Student st;
  Student *newStudent;
  int errorCode;
  char matricula[100];
  st.name = strdup("Ángel Pérez");
  st.semestre = 6;

  students = initDictionary(100, &errorCode);
  upsertDictionary(students, "0101", (void *)st, sizeof(Student), &errorCode);

  st.name = "Jesus López";
  st.semestre = 7;
  upsertDictionary(students, "0202", (void *)st, sizeof(Student), &errorCode);


  printf("What is the id: \n");
  scanf("%s\n",matricula );
  
  newStudent = (Student *)getDictionary(students, "0101", sizeof(Student), &errorCode);
  if(newStudent == NULL)
  {
    printf("Student not found \n", );
  }
  else
  {
    printf("name %s, semestre %d\n", newStudent->name, newStudent->semestre);
  }
  return 0;
}


//Hay muchas cosas aquí como printf y eso que no están en mi código

//si pongo gcc -c -o main.o main.c
//va a quedar con hoyos
//Esa es la etapa de enlazado en la compilación
//Eso pasa cuando no le paso la flag -c
//gcc -o students.exe main.o dict.o
//cuando no paso -c el compilador trata de hacer todo, si le paso los códigos objetos sólo intenta hacer el enlazado
//eso sucede con los includes

//gcc -o students.exe main.o dict.o
//gcc -o students.exe main.c dict.o

//No puedes incluir funciones en específico


//gcc -o students.exe
