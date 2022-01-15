#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define INF 9999

void floydWarshall(int G[MAX][MAX], int n) {
	int i, j, k;
	int D[MAX][MAX];
	int parent[n][n];
	for(i = 0; i<n; i++) {
		for(j = 0; j<n; j++) {
			D[i][j] = G[i][j];
			parent[i][j] = -1;
		}
	}
	
	for(k = 0; k<n; k++) {
		for(i = 0; i<n; i++) {
			for(j = 0; j<n; j++) {
				if(D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
					parent[i][j] = k;
				}
			}
		}
	}
	
	for(i = 0; i<n; i++) {
		for(j = 0; j<n; j++) {
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i<n; i++) {
		for(j = 0; j<n; j++) {
			printf("%d ", parent[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
//	int source;
//	scanf("%d", &source);
	int G[MAX][MAX];
	for(i = 0; i<n; i++) {
	    for(j = 0; j<n; j++) {
	        scanf("%d", &G[i][j]);
	    }
	}
	
	floydWarshall(G, n);
	
	return 0;
}
