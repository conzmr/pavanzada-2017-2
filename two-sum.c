#include <stdio.h>
#include <stdlib.h>

//Because I need to return an array, so I return an address to that array
int *getIndexes(int *nums, int len, int target)
{
  //&nums[0] = 8
  //sizeof returns the number of bytes
  int i,j;
  int candidate;
  int complement;
  // int result[2];
  int *result = (int *)calloc(2, sizeof(int));

  for(i=0; i<len-1; i++)
  {
    if(nums[i] >=target)
    {
      continue; //Allow us to go to the next instruction after for
    }
    candidate = nums[i];
    complement = target - candidate;
    for(j=i+1; j<len; j++)
    {
      if(nums[j] == complement)
      {
        break;
      }
    }
    if(nums[i]+nums[j] == target)
    {
      result[0] = i;
      result[1] = j;
      return result;
    }
  }
  return NULL; //In uppercase
}

int main()
{
  int nums[] = {2,7,11,15};
  int len = 4;
  int target = 9;
  int *result = getIndexes(nums, len, target);
  if(result != NULL && (nums[result[0]]+nums[result[1]]) == target)
  {
    printf("Works!\n");
  }else
  {
    printf(":(\n");
  }
}
//In c you can only return one variable
