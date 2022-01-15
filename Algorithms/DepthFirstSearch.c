#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct Stack
{
	int top;
	int size;
	int* arr;
};

struct Stack* createStack(int capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->size = capacity;
	stack->arr = (int *)malloc(capacity*sizeof(int));
	
	return stack;
}

int isEmpty(struct Stack* stack)
{
	if(stack->top == -1) {
		return 1;
	}
	return 0;
}

int isFull(struct Stack* stack)
{
	if(stack->top == stack->size - 1) {
		return 1;
	}
	return 0;
}

void push(struct Stack* stack, int data)
{
	if(isFull(stack)) {
		printf("The stack is full.");
	}
	else {
		stack->arr[++stack->top] = data;
	}
}

int pop(struct Stack* stack)
{
	if(isEmpty(stack)) {
		printf("The stack is empty.");
		return -1;
	}
	return stack->arr[stack->top--];
}

void depthFirstSearch(int G[MAX][MAX], int n, int start) {
	int i;
	int explored[n];
	for(i = 0; i<n; i++) {
		explored[i] = 0;
	}
	
	int visited = 0;
	struct Stack* stack = createStack(20);
	push(stack, start);
	while(!isEmpty(stack)) {
		int p = pop(stack);
		if(!explored[p]) {
			printf("%d ", p);
			explored[p] = 1;
			for(i = 0; i<n; i++) {
				if(G[p][i]) {
					push(stack, i);
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
							   {0, 1, 0, 0, 0},
							   {1, 0, 1, 1, 1},
							   {0, 1, 0, 1, 0},
							   {0, 1, 1, 0, 1},
							   {0, 1, 0, 1, 0},
							};
                              
	depthFirstSearch(graph, 5, 0);

//	depthFirstSearch(G, n, 0);
	
	return 0;
}
