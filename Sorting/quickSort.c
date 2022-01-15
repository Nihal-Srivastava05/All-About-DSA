#include<stdio.h>
#include<stdlib.h>

void swap(int*a, int*b) 
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int A[], int p, int q)
{
	swap(&A[p], &A[q]);
	int pivot = q;
	int i = p - 1;
	int j;
	for(j = p; j<=q; j++) {
		if(A[j] < A[pivot]) {
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	swap(&A[i+1], &A[q]);
	
	return i+1;
}

void quickSort(int A[], int p, int q)
{
	if(p<q) {
		int r = partition(A, p, q);
		quickSort(A, p, r-1);
		quickSort(A, r+1, q);
	}
}

int main()
{
	int A[] = {2, 5, 2, 9, 7, 6 ,0};
	int n=7, i;
//	int n, i;
//    scanf("%d", &n);
//    int A[n];
//    for(i = 0; i<n; i++) {
//        scanf("%d", &A[i]);
//    }
    
	quickSort(A, 0, n-1);

	for(i = 0; i<n; i++) {
		printf("%d ", A[i]);
	}
	
	return 0;
}
