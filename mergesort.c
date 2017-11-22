#include <stdio.h>
#include <stdlib.h>

void mergeSort(int array[], int startIndx, int endIndx);
void merge(int array[], int l, int m, int r);


int main(int argc, char *argv[]){
  int array[10] = {33,4,13,6,65,2,21,99,1,45};
  int n = sizeof(array) / sizeof(array[0]);
  mergeSort(array, 0, n-1);
  for(int i = 0; i < n; i++){
    printf("%d, ", array[i]);
  }
}

void mergeSort(int array[], int startIndx, int endIndx){
  if(startIndx < endIndx){ //base case only 1 element in the array so return
    int m = (startIndx + endIndx) / 2;
    mergeSort(array, startIndx, m);
    mergeSort(array, m + 1, endIndx);
    merge(array, startIndx, m, endIndx);
  }
}


void merge(int array[], int l, int m, int r){
  int lN = m - l + 1;
  int rN = r - m;
  int L[lN];
  int R[rN];
  //copy items into respective arrays
  for(int i=0; i < lN; i++){
    L[i] = array[l + i];
  }
  for(int i=0; i < rN; i++){
    R[i] = array[m + 1 + i];
  }

  //copy items into array by comparing each unsorted smallest item of the two arrays
  int iL = 0;
  int iR = 0;
  int k = l;
  //RETARD THIS IS WHERE YOU ARE COPYING BACK INTO THE ARRAY! OBVIOUSLY NOT ZERO BECAUSE YOU COULD BE AT THE FUCKING RIGHT SIDE OF THE ARRAY
  while(iL < lN && iR < rN){
    if(L[iL] <= R[iR]){
      array[k] = L[iL];
      iL ++;
    }else{
      array[k] = R[iR];
      iR++;
    }
    k++;
  }

  //copy remaining items
  while(iL < lN){
    array[k] = L[iL];
    iL++;
    k++;
  }

  while(iR < rN){
    array[k] = R[iR];
    iR++;
    k++;
  }
}
