#include<stdio.h>
#include<stdlib.h>

void merge(int A[], int p, int m, int r) {
	int n1 = m - p + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    
	int i, j, k;
	for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];	
	
	i = 0;
	j = 0;
	k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
		    A[k] = L[i];
		    i++;
		}
		else {
		    A[k] = R[j];
		    j++;
		}
		k++;
	}
	
	while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int l, int r) {
	if(r > l) {
		int m = (l+r)/2;
		mergeSort(A, l, m);
		mergeSort(A, m+1, r);
		merge(A, l, m, r);
	}
}

int main()
{
	int A[] = {2, 5, 2, 9, 7, 6 ,1};
	int arr_size = sizeof(A) / sizeof(A[0]);
	mergeSort(A, 0, arr_size-1);
	int i;
	for(i = 0; i<7; i++) {
		printf("%d ", A[i]);
	}
	
	return 0;
}

