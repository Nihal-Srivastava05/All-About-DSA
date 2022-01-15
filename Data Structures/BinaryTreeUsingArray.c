#include<stdio.h>
#include<stdlib.h>

struct binaryTree {
	int size;
	int* arr;
	int index;
};

struct binaryTree* createTree(int n) {
	struct binaryTree* tree = (struct binaryTree*)malloc(sizeof(struct binaryTree));
	tree->index = 0;
	tree->size = n;
	tree->arr = (int *)malloc(n * sizeof(int));
	
	return tree;
}

void insertNode(struct binaryTree* tree, int value) {
	if(tree->index == tree->size) {
		printf("Tree Full.\n");
		return;
	}
	else {
		tree->index++;
		tree->arr[tree->index] = value;
	}
}

void deleteNode(struct binaryTree* tree, int value) {
	int i;
	for(i = 0; i<=tree->index; i++) {
		if(tree->arr[i] == value) {
			tree->arr[i] = tree->arr[tree->index];
			tree->index--;
			break;
		}
	}
}

void deleteTree(struct binaryTree* tree) {
	tree->arr = NULL;
}

int searchNodes(struct binaryTree* tree, int value) {
	int i;
	for(i = 0; i<=tree->index; i++) {
		if(tree->arr[i] == value) {
			return i;
		}
	}
	
	return -1;
}

void inOrder(struct binaryTree* tree, int index) {
	if(index > tree->index) {
		return;
	}
	else {
		inOrder(tree, index*2);
		printf("%d ", tree->arr[index]);
		inOrder(tree, index*2 + 1);
	}
}

void preOrder(struct binaryTree* tree, int index) {
	if(index > tree->index) {
		return;
	}
	else {
		printf("%d ", tree->arr[index]);
		preOrder(tree, index*2);
		preOrder(tree, index*2 + 1);
	}
}

void postOrder(struct binaryTree* tree, int index) {
	if(index > tree->index) {
		return;
	}
	else {
		postOrder(tree, index*2);
		postOrder(tree, index*2 + 1);
		printf("%d ", tree->arr[index]);
	}
}

void levelOrder(struct binaryTree* tree) {
	int i;
	for(i = 1; i<=tree->index; i++) {
		printf("%d ", tree->arr[i]);
	}
}

int main()
{
	int n, ele, i;
	scanf("%d", &n);
	struct binaryTree* tree = createTree(n);
	for(i = 0; i<n; i++) {
		scanf("%d", &ele);
		insertNode(tree, ele);
	}
	
	printf("Pre order: \n");
	preOrder(tree, 1);
	
	printf("\nIn order: \n");
	inOrder(tree, 1);
	
	printf("\nPost order: \n");
	postOrder(tree, 1);
	
	printf("\nLevel order: \n");
	levelOrder(tree);
	
	return 0;
}

