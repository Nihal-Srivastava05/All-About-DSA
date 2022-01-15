#include<stdio.h>
#include<stdlib.h>

#define MAX 30

typedef struct edge {
	int start;
	int end;
	int weight;
} edge;

typedef struct edge_list {
	edge data[MAX];
	int n;
} edge_list;

edge_list elist;
int Graph[MAX][MAX];
int n;
edge_list spanlist;

int find(int vertices[], int vno) {
	return (vertices[vno]);
}

void applyUnion(int vertices[], int c1, int c2) {
	int i;
	for(i = 0; i<n; i++) {
		if(vertices[i] == c2) {
			vertices[i] = c1;
		}
	}
}

void sort() {
	int i,j;
	edge temp;
	
	for(i = 1; i<elist.n; i++) {
		for(j = 0; j<elist.n - 1; j++) {
			if(elist.data[j].weight > elist.data[j+1].weight) {
				temp = elist.data[j];
       			elist.data[j] = elist.data[j + 1];
        		elist.data[j + 1] = temp;
			}
		}
	}
}

void print() {
	int i;
	int cost = 0;
	for(i = 0; i<spanlist.n; i++) {
		printf("%d - %d: %d", spanlist.data[i].start, spanlist.data[i].end, spanlist.data[i].weight);
		cost += spanlist.data[i].weight;
	}
	printf("Total Cost: %d", cost);
}

void kruskal() {
	int vertices[MAX], i, j, r1, r2;
	elist.n = 0;
	
	for(i = 1; i<n; i++) {
		for(j = 0; j<i; j++) {
			if(Graph[i][j] != 0) {
				elist.data[elist.n].start = i;
				elist.data[elist.n].end = j;
				elist.data[elist.n].weight = Graph[i][j];
				elist.n++;
			}
		}
	}
	
	sort();
	
	for (i = 0; i < n; i++){
		vertices[i] = i;
	}
	
	spanlist.n = 0;
	
	for(i = 0; i<elist.n; i++) {
		r1 = find(vertices, elist.data[i].start);
		r2 = find(vertices, elist.data[i].end);
		
		if(r1 != r2) {
			spanlist.data[spanlist.n] = elist.data[i];
			spanlist.n = spanlist.n + 1;
			applyUnion(vertices, r1, r2);
		}
	}
	
	print();
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for(i= 0; i<n; i++) {
	    for(j = 0; j<n; j++) {
	        scanf("%d", &Graph[i][j]);
	    }
	}
	
	kruskal();
		
	return 0;
}
