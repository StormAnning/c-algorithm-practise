#include <stdio.h>
#include <stdlib.h>

void quicksort(int array[], int start, int end);
int partition(int array[], int start, int end);
void swap(int* a, int* b);
int main(int argc, char const *argv[])
{
	int array[10] = {5,43,54,22,99,18,86,34,65,12};
  	int n = sizeof(array) / sizeof(array[0]);
	quicksort(array, 0, n-1);

	for(int i=0; i < 10; i++){
		printf("%d ",array[i] );
	}
	return 0;
}

void quicksort(int array[], int start, int end)
{
	if((end - start) > 0)
	{
		int pivot = partition(array, start, end);
		quicksort(array, start, pivot-1);
		quicksort(array, pivot + 1, end);
	}
}


int partition(int array[], int start, int end)
{
	int pivot = end;
	int lastIndexHigherThanPivot = start;
	for(int i = start; i<end; i++)
	{
		if(array[i] < array[pivot])
		{
			swap(&array[i], &array[lastIndexHigherThanPivot]);
			lastIndexHigherThanPivot++;
		}
	}
	swap(&array[lastIndexHigherThanPivot], &array[pivot]);
	return lastIndexHigherThanPivot;
}


void swap(int *a, int *b)
{
	int tpm = *a;
	*a = *b;
	*b = tpm;
}


