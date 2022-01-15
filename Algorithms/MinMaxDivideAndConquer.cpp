#include<stdio.h>
#include<stdlib.h>

struct pair
{
	int min;
	int max;
};

struct pair minMax(int A[], int start, int end)
{
	struct pair minmax, left, right;
	
	if(start == end) {
		minmax.max = A[start];
		minmax.min = A[start];
		
		return minmax;
	}
	else if(start + 1 == end) {
		if(A[start] < A[end]) {
			minmax.min = A[start];
			minmax.max = A[end];
		}
		else {
			minmax.min = A[end];
			minmax.max = A[start];
		}
		
		return minmax;
	}
	else {
		int mid = (start + end)/2;
		left = minMax(A, start, mid);
		right = minMax(A, mid+1, end);
		if(left.max > right.max) {
			minmax.max = left.max;
		}
		else{
			minmax.max = right.max;
		}
		
		if(left.min < right.min) {
			minmax.min = left.min;
		}
		else {
			minmax.min = right.min;
		}
	}
	
	return minmax;
}

int main()
{
	int A[] = {5, 0, 10, 33, 2, 4, 91, 3};
	struct pair ans = minMax(A, 0, 7);
	printf("MAX: %d MIN: %d", ans.max, ans.min);
	
	return 0;
}
