#include<stdio.h>
#include<stdlib.h>

void selectionSort(int A[], int n)
{
	int i, j;
	for(j = 0; j<n-1; j++) {
		int imin = j;
		for(i = j+1; i<n; i++) {
			if(A[i] < A[imin]) {
				imin = i;
			}
		}
		if(imin != j) {
			int temp = A[j];
			A[j] = A[imin];
			A[imin] = temp;
		}
	}
	
	for(i = 0; i<n; i++) {
		printf("%d ", A[i]);
	}
}

int main()
{
	int A[] = {2, 5, 2, 9, 7, 6 ,0};
	selectionSort(A, 7);
	
	return 0;
}
