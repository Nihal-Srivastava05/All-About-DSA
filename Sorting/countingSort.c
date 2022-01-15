#include<stdio.h>
#include<stdlib.h>

void countingSort(int A[], int B[], int k, int n)
{
	int i, j;
	int C[k];
	for(i = 0; i<k; i++) {
		C[i] = 0;
	}
	for(j = 0; j<n; j++) {
		C[A[j]] = C[A[j]] + 1;
	}
	
	for(i = 0; i<=k; i++ ) {
		C[i] = C[i] + C[i-1];
	}
		
	for(j = n-1; j>=0; j--) {
		B[ C[A[j]] - 1 ] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
	
	for(i = 0; i<n; i++) {
		printf("%d ", B[i]);
	}
}

int main()
{
	int i;
	int A[] = {2, 5, 3, 0, 2, 3, 0, 3};
	int B[8];
	
	countingSort(A, B, 5, 8);
	
	return 0;
}
