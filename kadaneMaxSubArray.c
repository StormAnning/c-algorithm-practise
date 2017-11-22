#include <stdio.h>
#include <stdlib.h>

int kadaneMaxSubArray(int array[], int n);

int main(int argc, char *argv[]){
  int array[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
  int max = kadaneMaxSubArray(array,16);
  printf("%d\n", max);
}

int kadaneMaxSubArray(int array[], int n){ //O(n)
  int maxSumFoundOverEntireArray = array[0];
  int currentMax = array[0];
  for(int i=0; i<n; i++){
    currentMax = (currentMax + array[i] > array[i] ? currentMax + array[i] : array[i]);
    if(currentMax > maxSumFoundOverEntireArray){
      maxSumFoundOverEntireArray = currentMax;
    }
  }
  return maxSumFoundOverEntireArray;
}
