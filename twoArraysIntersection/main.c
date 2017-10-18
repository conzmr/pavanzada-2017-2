#include <stdlib.h>
#include <stdio.h>
#include "twoArraysIntersection.h"

int main(int argc, char **argv) {
  int nums1Size = 10;
  int nums2Size = 8;
  int n1[10] = {100, 54, 3,47,76,8653,7,877,8,1};
  int n2[8] = {23,4,6,234,12,47,76,8653};
  int *nums1 = (int *) malloc(nums1Size * sizeof( int ));
  int *nums2 = (int *) malloc(nums2Size * sizeof( int ));
  for(int i=0;i<nums1Size;i++){
    nums1[i] = n1[i];
  }
  for(int j=0;j<nums2Size;j++){
    nums2[j] = n2[j];
  }
  int returnSize = 0;
  int *array = intersection(nums1 , nums1Size , nums2 , nums2Size, &returnSize);
  printf("Return Size %d\n", returnSize);
  for(int k=0;k<returnSize;k++){
    printf("%d\n",array[k]);
  }
  return 0;
}
