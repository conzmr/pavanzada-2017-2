#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "keyboardRow.h"

int inOneRow(char **rows, char *word, int index){
  int isIn;
  for(int i=0; word[i]!= '\0'; i++){
    isIn = 0;
    for(int j=0; rows[index][j] != '\0'; j++){
      if(word[i] == rows[index][j]){
        isIn = 1;
        break;
      }
    }
    if(isIn == 0){
      return 0;
    }
  }
  return 1;
}

int selectRow(char **rows, int *rowsLength, char *firstLetter){
  for(int i = 0; i<rowsLength[0]; i++){
    if(firstLetter == rows[0][i]){
      return 0;
    }
    if(i<rowsLength[1]){
      if(firstLetter == rows[1][i]){
        return 1;
      }
    }
    if(i<rowsLength[2]){
      if(firstLetter == rows[2][i]){
        return 2;
      }
    }
  }
  return 0;
}


/** findWords
  * Receives an array of char * (strings) and a pointer to the size of the
  * result. It returns the words that can be formed using only a row of the
  * standard US Keyboard layout.
  * Notes:
  *   - You may use one character in the keyboard more than once.
  *   - You may assume the input string will only contain letters of alphabet.
  * @param:
  *  words: the input array of char *
  *  words_size: the size of the char ** words
  *  return_size: the direction in memory in which to save the result's size.
  * @return:
  *  char **: the words that can be formed.
*/
char** findWords(char** words, int wordsSize, int* returnSize) {
  char *keyboard[3];
  keyboard[0] = "qwertyuiop";
  keyboard[1] = "asdfghjkl";
  keyboard[2] = "zxcvbnm";
  int rowsLength[3] = {10,9,7};
  int results[wordsSize];
  char firstLetter;
  int row;
  int wordsCount = 0;
  char **finalWords;
  firstLetter = 'd';
  inOneRow(&*keyboard, words[0], 1);
  for(int i = 0; i < wordsSize; i++){
    row = selectRow(&*keyboard, &rowsLength, words[i][0]);
    results[i] = inOneRow(&*keyboard, words[i], row);
    if(results[i]==1){
      wordsCount++;
    }
  }
  finalWords = (char **) malloc(wordsCount * sizeof(char *));
  int j = 0;
  for (int i = 0; i < wordsSize; i++) {
        if (results[i] == 1) {
            finalWords[j] = malloc(256 * sizeof(char));
            strcpy(finalWords[j], words[i]);
            j++;
        }
  }
  *returnSize = wordsCount;
  printf("%s\n", finalWords[0]);
  printf("%s\n", finalWords[1]);
  return finalWords;
}
