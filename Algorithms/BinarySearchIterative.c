#include<stdio.h>
#include<stdlib.h>

int binarySearch(int A[], int n, int key)
{
	int low = 0;
	int high = n-1;
	int m;
	while(low <= high) {
		m = (low + high)/2;
		if(key == A[m]) {
			return m;
		}
		else if(key < A[m]) {
			high = m - 1;
		}
		else {
			low = m + 1;
		}
	}
	return -1;
}

int main()
{
	int A[] = {0, 1, 2, 3, 4, 5, 6};
	int index = binarySearch(A, 7, 3);
	printf("%d", index);
	
	return 0;
}
