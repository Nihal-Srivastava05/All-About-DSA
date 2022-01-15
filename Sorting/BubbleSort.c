#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int A[], int n)
{
	int i, j;
	for(i = 0; i<n-1; i++) {
		for(j = 0; j<n-i-1; j++) {
			if(A[j] > A[j+1]) {
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
	
	for(i = 0; i<n; i++) {
		printf("%d ", A[i]);
	}
}

int main()
{
	int A[] = {2, 5, 2, 9, 7, 6 ,0};
	bubbleSort(A, 7);
	
	return 0;
}
