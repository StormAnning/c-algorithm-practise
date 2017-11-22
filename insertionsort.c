#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int n);

int main(int argc, char *argv[]){
  int unsrted[10] = {33,4,13,6,65,2,21,99,1,45};
  int n = sizeof(unsrted) / sizeof(unsrted[0]);
  insertionSort(unsrted,n);

  for(int i = 0; i < n; i++){
    printf("%d, ", unsrted[i]);
  }
}

void insertionSort(int array[], int n){
  //first element is sorted, go through each element and shift it into thet sorted protion
  for(int i = 1; i < n; i ++){
    int element = array[i];
    int j = i;
    while(j > 0 && array[j-1] > element){
      array[j] = array[j-1];
      j--;
    }
    array[j] = element;
  }
}
