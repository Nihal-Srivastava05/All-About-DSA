#include<stdio.h>
#include<stdlib.h>

void insertionSort(int A[], int n)
{
	int i, j, currentNumber;
	for(i = 1; i<n; i++) {
		currentNumber = A[i];
		j = i;
		while(A[j-1] > currentNumber && j>0) {
			A[j] = A[j-1];
			j--;
		}
		A[j] = currentNumber;
	}
	
	for(i = 0; i<n; i++) {
		printf("%d ", A[i]);
	}
}

int main()
{
	int A[] = {2, 5, 2, 9, 7, 6 ,0};
	insertionSort(A, 7);
	
	return 0;
}
