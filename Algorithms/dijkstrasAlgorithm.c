#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10
#define INF 99999

void printArray(int arr[], int n) {
	int i;
	printf("[ ");
	for(i = 0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

void dijkstras(int G[MAX][MAX], int n, int source) {
	int dist[n];
	int visited[n];
	int parent[n];
	int i, j;
	for(i = 0; i<n; i++) {
		dist[i] = INF;
		visited[i] = false;
		parent[i] = -1;
	}

	dist[source] = 0;	
	for(i = 0; i<n; i++) {
		int min_dist = INF;
		int index = 0;
		for(j = 0; j<n; j++) {
			if(!visited[j] && min_dist > dist[j]) {
				min_dist = dist[j];
				index = j;
			}
		}
		
		visited[index] = true;
		
		for(j = 0; j<n; j++) {
			if(G[index][j]) {
				if(dist[j] > dist[index] + G[index][j]) {
					dist[j] = dist[index] + G[index][j];
					parent[j] = index;
				}
			}
		}
	}
	printArray(dist, n);
	printArray(parent, n);
	
	for(i = 0; i<n; i++) {
		printf("(%d - %d) ==> %d\n", parent[i], i, dist[i]);
	}
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int source;
	scanf("%d", &source);
	int G[MAX][MAX];
	for(i = 0; i<n; i++) {
	    for(j = 0; j<n; j++) {
	        scanf("%d", &G[i][j]);
	    }
	}
	
	dijkstras(G, n, source);
	
	return 0;
}
