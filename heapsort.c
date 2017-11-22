#include <stdio.h>
#include <stdlib.h>

int heap_size;

int main(int argc, char *argv[]){
	heap_size = 0;
	int array[16] = {3,66,34,11,44,1,5,7,88,5,88,76,1,22,57,88};
}


void maxHeapify(int array[], int i, int n){
	//assume children are valid max heaps!
	//look at the left child
	//look at the right child
	//swap the larger of the two with i
	int left = 2*n;
	int right = left + 1;
	int temp = array[i];
	int largerIndex;

	if(array[left] >= array[i]){
		largerIndex = left
	}else if(array[right] >= array [i]){
		largerIndex = right;
	}else{
		return;
	}

	if(largerIndex <= n/2){ //heap size...
		array[i] = array[largerIndex];
		array[largerIndex] = temp;
		max_heapify(array, largerIndex, n)
	}
}

void buildMaxHeap(int array[]){
	//for n/2 +1 to n call max_heapify...

}