#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct buckets
{
	int* arr;
};

void sortBuckets(struct buckets bkts[], int n, int indexs[])
{
	int i, x;
	
	for(i = 0; i<n; i++) {
		int j, k, current;
		for(j = 0; j<indexs[i]; j++) {
			current = bkts[i].arr[j];
			k = j;
			while(bkts[i].arr[k - 1] > current && k > 0) {
				bkts[i].arr[k] = bkts[i].arr[k - 1];
				k--;
			}
			bkts[i].arr[k] = current;
		}
	}
}

void concatenate(struct buckets bkts[],int indexes[], int n, int N) {
	int i, j;
	int arr[N];
	int idx = 0;
	for(i = 0; i<n; i++) {
		for(j = 0; j<indexes[i]; j++) {
			arr[idx] = bkts[i].arr[j];
			idx++;
		}
	}
	
	for(i = 0; i<N; i++) {
		printf("%d ", arr[i]);
	}
}

void bucketSort(int A[], int n)
{
	int numOfBucket = (int)ceil(sqrt(n));
	struct buckets bkts[numOfBucket];
	int indexes[numOfBucket] = {0};
	int i;
	
	for(i = 0; i<numOfBucket; i++) {
		bkts[i].arr = (int*)malloc(n*sizeof(int));
	}
	
	int max_num = A[0];
	for(i = 0; i<n; i++) {
		if(A[i] > max_num) {
			max_num = A[i];
		}
	}
	for(i = 0; i<n; i++) {
		int indexOfBucket = (int)ceil((A[i] * numOfBucket) / max_num);
		if(indexOfBucket == numOfBucket) {
			indexOfBucket -= 1;
		}
		bkts[indexOfBucket].arr[indexes[indexOfBucket]] = (int)A[i];
		indexes[indexOfBucket] += 1;
	}

	sortBuckets(bkts, numOfBucket, indexes);
	concatenate(bkts, indexes, numOfBucket, n);
}

int main()
{
	int A[] = {2, 5, 2, 9, 7, 6 ,0};
	bucketSort(A, 7);
	
	return 0;
}
