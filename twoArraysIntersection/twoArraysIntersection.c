#include <stdlib.h>
#include <stdio.h>
#include "twoArraysIntersection.h"

/***********************
* intersection
* Given two arrays, write a function to compute their intersection.
* Notes:
* - Each element in the result must be unique.
* - The result can be in any order.
* @param:
* nums1: integer array
* nums1Size: size of nums1 array
* nums2: integer array
* nums2Size: size of nums2 array
* returnSize: size of return array
* @return:
* array: intersection
*/
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int *returnArray;
  int numCounter = 0;
  int temp[nums1Size];
  int isIn = 0;
  for(int i=0; i<nums1Size; i++) {
    for(int j=0; j<nums2Size; j++) {
      isIn = 0;
      for(int k= 0; k<numCounter; k++){
        if(nums2[j] == temp[k]){
          isIn = 1;
          break;
        }
      }
      if(isIn){
        continue;
      }
      if(nums1[i] == nums2[j]){
        temp[numCounter] = nums1[i];
        numCounter++;

      }
    }
  }
  returnArray = (int *) malloc(numCounter * sizeof( int ));
  for(int i=0;i<numCounter;i++){
    returnArray[i] = temp[i];
  }
  *returnSize = numCounter;
  return returnArray;
}
