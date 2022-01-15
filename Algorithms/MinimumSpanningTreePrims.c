#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define INF 999999
#define MAX 6

void prims(int G[MAX][MAX], int n, int start) {
	int edge;
	int visited[n];
	int i, j;
	for(i = 0; i<n; i++) {
		visited[i] = false;
	}
	
	edge = 0;
	visited[start] = true;
	int x, y;
	int cost = 0;
	
	while(edge < n-1) {
		int min = INF;
		x = 0;
		y = 0;
		for(i = 0; i<n; i++) {
			if(visited[i]) {
				for(j = 0; j<n; j++) {
					if(!visited[i] && G[i][j]) {
						if(min > G[i][j]) {
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
			printf("(%d - %d): %d\n", x, y, G[x][y]);
			cost += G[x][y];
			visited[y] = true;
			edge++;
		}
		
		printf("Cost: %d", cost);
	}
	
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int start;
	scanf("%d", &start);
	int G[6][6];
	for(i = 0; i<n; i++) {
	    for(j = 0; j<n; j++) {
	        scanf("%d", &G[i][j]);
	    }
	}
	
	prims(G, n, start);
		
	return 0;
}
