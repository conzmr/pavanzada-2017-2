#include <stdio.h>

// int main(){
//   printf("Hello World\n");
//   return 0;
// }

int main(int argn, char ** argv){
  int i;
  for(i=1; i<argn ; i++){
    //The first argument is my executable file name
    printf("Hello World %s \n", argv[i]);
  }
  return 0;
}
