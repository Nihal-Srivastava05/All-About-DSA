#include<stdio.h>
#include<stdlib.h>

void deleteElement(int n, int N[10], int index)
{
	int i;
	for(i = index; i<n; i++) {
		N[i] = N[i+1];
	}
}

int josephus(int n, int N[10],int index, int k)
{
	if(n == 1){
		return N[0];
	}
	else{
		int indexToDelete = (index+k-1)%n;
		deleteElement(n, N, indexToDelete);
		return josephus(n-1, N, indexToDelete, k);
	}
		
}

int main()
{
	int n, k, i;
	int N[10];
	scanf("%d", &n);
	for(i = 0; i<n; i++) {
		scanf("%d", &N[i]);
	}
	scanf("%d", &k);
	
	int ans = josephus(n, N, 0, k);
	printf("%d", ans);
	
	return 0;
}
