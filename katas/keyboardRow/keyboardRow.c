#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "keyboardRow.h"

/***********************
* inOneRow
* Given a word and row, returns if could be typed complete within .
* @param:
* rows: array with three keyboard rows as strings
* rowsLength: int array with the size of each alphabet row
* firstLetter: first character in a word
* @return:
* integer: 0 || 1 || 2
*/
int inOneRow(char *row, char *word, int index){
  int isIn;
  for(int i=1; word[i]!= '\0'; i++){
    isIn = 0;
    for(int j=0; row[j] != '\0'; j++){
      if(word[i] == row[j]){
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

/***********************
* selectRow
* According to the first letter of a word, determines in which row 0, 1 or 2
* should the entire word be.
* @param:
* rows: array with three keyboard rows as strings
* rowsLength: int array with the size of each alphabet row
* firstLetter: first character in a word
* @return:
* integer: 0 || 1 || 2
*/
int selectRow(char **rows, int *rowsLength, char firstLetter){
  firstLetter = tolower(firstLetter);
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
  return -1;
}


/***********************
* findWords
* Given a list of words, return the words that can be typed using letters of
* alphabet on only one row's of American keyboard.
* Notes:
* 1. You may use one character in the keyboard more than once.
* 2. You may assume the input string will only contain letters of alphabet.
* @param:
* words: input words as array of strings
* wordsSize: the size of words array
* returnSize: int pointer to output's array size
* @return:
* char **: string array with the words that can be typed with one row.
*/
char** findWords(char** words, int wordsSize, int* returnSize) {
  char *keyboard[3];
  keyboard[0] = "qwertyuiop";
  keyboard[1] = "asdfghjkl";
  keyboard[2] = "zxcvbnm";
  int rowsLength[3] = {10,9,7};
  int results[wordsSize];
  int row;
  int wordsCount = 0;
  char **finalWords;
  for(int i = 0; i < wordsSize; i++){
    row = selectRow(&*keyboard, rowsLength, words[i][0]);
    results[i] = inOneRow(keyboard[row], words[i], row);
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
  return finalWords;
}
