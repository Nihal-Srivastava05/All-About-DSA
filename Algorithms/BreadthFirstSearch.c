#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct Queue {
	int top, beg, size;
	int *arr;
};

struct Queue* createQueue(int n) {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->top = -1;
	queue->beg = -1;
	queue->size = n;
	queue->arr = (int *)malloc(n * sizeof(int));
	
	return queue;
}

int isFull(struct Queue* queue)
{
	if(queue->top == queue->size - 1) {
		return 1;
	}
	return 0;
}

int isEmpty(struct Queue* queue)
{
	if(queue->top == -1) {
		return 1;
	}
	return 0;
}

void enQueue(struct Queue* queue, int data)
{
	if(isFull(queue)) {
		printf("Queue is full.");
	}
	else{
		queue->arr[++queue->top] = data;
	}
}

int deQueue(struct Queue* queue)
{
	if(isEmpty(queue)) {
		printf("The queue is empty.");
	}
	else {
		int ele = queue->arr[++queue->beg];
		if(queue->beg > queue->top) {
			queue->top = -1;
			queue->beg = -1;
		}
		return ele;
	}
}

void breadthFirstSearch(int G[MAX][MAX], int n, int start) {
	int i;
	int explored[n];
	for(i = 0; i<n; i++) {
		explored[i] = 0;
	}
	struct Queue* queue = createQueue(30);
	enQueue(queue, start);
	while(!isEmpty(queue)) {
		int p = deQueue(queue);
		if(!explored[p]) {
			printf("%d ", p);
			explored[p] = 1;
			for(i = 0; i<n; i++) {
				if(G[i][p]) {
					enQueue(queue, i);
				}
			}
		}
	}
}

int main()
{
	int n, i, j;
//	scanf("%d", &n);
//	int G[MAX][MAX];
//	
//	for(i = 0; i<n; i++) {
//		for(j = 0; j<n; j++) {
//			scanf("%d", &G[i][j]);
//		}
//	}
	
	int graph[MAX][MAX] = {
							   {0, 1, 1, 1, 0, 0},
							   {1, 0, 0, 1, 1, 0},
							   {1, 0, 0, 1, 0, 1},
							   {1, 1, 1, 0, 1, 1},
							   {0, 1, 0, 1, 0, 1},
							   {0, 0, 1, 1, 1, 0}
							};
                              
	breadthFirstSearch(graph, 6, 1);

//	breadthFirstSearch(G, n, 0);s
	
	return 0;
}
