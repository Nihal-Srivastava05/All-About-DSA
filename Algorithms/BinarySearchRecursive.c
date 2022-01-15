#include<stdio.h>
#include<stdlib.h>

int binarySearch(int A[], int first, int last, int key) 
{
	int index;
	if(last < first) {
		index = -1;
	}
	else {
		int m = (first + last)/2;
		if(key == A[m]) {
			index = m;
		}
		else if(key < A[m]) {
			binarySearch(A, first, m - 1, key);
		}
		else {
			binarySearch(A, m+1, last, key);
		}
	}
	return index;
}

int main()
{
	int A[] = {0, 1, 2, 3, 4, 5, 6};
	int index = binarySearch(A, 0, 7, 3);
	printf("%d", index);
	
	return 0;
}
