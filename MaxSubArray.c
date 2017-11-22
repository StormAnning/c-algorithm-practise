#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int array[], int l, int r);
int maxCrossOver(int array[], int l, int m, int r);

int main(int argc, char *argv[]){
  int array[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
  int max = maxSubArray(array,0,15);
  printf("%d\n", max);
}

int maxCrossOver(int array[], int l, int m, int r){ //O(n)
  int leftSumMax = 0;
  int leftSum =0;
  //check left max sum
  for(int i = m; i>=l; i--){
    leftSum = leftSum + array[i];
    if(leftSum> leftSumMax){
      leftSumMax = leftSum;
    }
  }

  int rightSumMax = 0;
  int rightSum=0;

  for(int i = m+1; i<=r; i++){
    rightSum = rightSum + array[i];
    if(rightSum > rightSumMax){
      rightSumMax = rightSum;
    }
  }
  printf("%s %d %d\n", "maxxCross - l, r:", leftSumMax, rightSumMax);
  return leftSumMax + rightSumMax;
}

int maxSubArray(int array[], int l, int r){ //O(log n)
  if(l == r){ //one element
    return array[l];
  }else{
    int mid = (l + r)/2;
    int left = maxSubArray(array,l,mid);
    int right = maxSubArray(array,mid+1, r);
    int crossOver = maxCrossOver(array,l,mid,r);

    if(left > right && left > crossOver){
      return left;
    }else if(right > left && right > crossOver){
      return crossOver;
    }else{
      return crossOver;
    }
  }
}
