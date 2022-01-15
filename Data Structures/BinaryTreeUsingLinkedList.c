#include<stdlib.h>
#include<stdio.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct binaryTree {
	struct node* root;
};

struct Queue {
	int top, beg, size;
	struct node* *arr;
};

struct Queue* createQueue(int sz) {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->top = -1;
	queue->beg = -1;
	queue->size = sz;
	queue->arr = (struct node**)malloc(sz * sizeof(struct node));
	
	return queue;
}

void enQueue(struct Queue* queue, struct node* current) {
	if(queue->top == queue->size - 1) {
		printf("Queue is Full");
		return;
	}
	else {
		queue->arr[++queue->top] = current;
	}
}

struct node* deQueue(struct Queue* queue) {
	if(queue->top == -1) {
		printf("Queue is empty");
		return;
	}
	else {
		struct node* temp =  queue->arr[++queue->beg];;
		if(queue->beg > queue->top) {
			queue->top = -1;
			queue->beg = -1;
		}
		return temp;
	}
}

struct binaryTree* createTree(int value) {
	struct binaryTree* tree = (struct binaryTree*)malloc(sizeof(struct binaryTree));
	tree->root = (struct node*)malloc(sizeof(struct node));
	tree->root->data = value;
	tree->root->left = NULL;
	tree->root->right = NULL;
	
	return tree;
}

struct node* createNode(int value)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = value;
	temp->right = NULL;
	temp->left = NULL;
	
	return temp;
}

void preOrder(struct node* root) {
	if(root == NULL) {
		return;
	}
	else {
		if(root->data != -1) {
			printf("%d ", root->data);
		}
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct node* root) {
	if(root == NULL) {
		return;
	}
	else {
		inOrder(root->left);
		if(root->data != -1) {
			printf("%d ", root->data);
		}
		inOrder(root->right);
	}
}

void postOrder(struct node* root) {
	if(root == NULL) {
		return;
	}
	else {
		postOrder(root->left);
		postOrder(root->right);
		if(root->data != -1) {
			printf("%d ", root->data);
		}
	}
}

void levelOrder(struct node* root) {
	struct Queue* queue = createQueue(20);
	enQueue(queue, root);
	while(queue->top != -1 && queue->top != queue->beg) {
		struct node* temp = deQueue(queue);
		if(temp->left != NULL) {
			enQueue(queue, temp->left);
		}
		if(temp->right != NULL) {
			enQueue(queue, temp->right);
		}
		if(root->data != -1) {
			printf("%d ", temp->data);
		}
	}
}

void insertNode(struct node* root, int value) {
	struct node* current = createNode(value);
	if(root == NULL) {
		root = current;
		return;
	}
	else {
		struct Queue* queue = createQueue(20);
		enQueue(queue, root);
		while(1) {
			struct node* temp = deQueue(queue);
			if(temp->left != NULL && temp->right != NULL) {
				enQueue(queue, temp->left);
				enQueue(queue, temp->right);
			}
			else {
				if(temp->left == NULL) {
					temp->left = current;
					enQueue(queue, temp->left);
				}
				else {
					temp->right = current;
					enQueue(queue, temp->right);
				}
				break;
			}
		}
		
	}
}

void deleteNode(struct node* root, int value) {
	struct Queue* queue = createQueue(20);
	struct node* temp;
	enQueue(queue, root);
	while(queue->top != -1 && queue->top != queue->beg) {
		temp = deQueue(queue);
		if(temp->left != NULL) {
			enQueue(queue, temp->left);
		}
		if(temp->right != NULL) {
			enQueue(queue, temp->right);
		}
	}
	struct node* deepest = temp;
	struct Queue* q = createQueue(20);
	enQueue(q, root);
	while(q->top != -1 && q->top != queue->beg) {
		struct node* t = deQueue(q);
		enQueue(q, t->left);
		enQueue(q, t->right);
		if(t->data == value) {
			t->data = deepest->data;
			break;
		}
	}
	deepest->data = -1;
	deepest = NULL;
}

void deleteTree(struct node* root) {
	root = NULL;
}

int main()
{
	int n, ele, i;
	scanf("%d", &n);
	scanf("%d", &ele);
	struct binaryTree* tree = createTree(ele);
	for(i = 0; i<n-1; i++) {
		scanf("%d", &ele);
		insertNode(tree->root, ele);
	}
	
	printf("Pre order: \n");
	preOrder(tree->root);
	
	printf("\nIn order: \n");
	inOrder(tree->root);
	
	printf("\nPost order: \n");
	postOrder(tree->root);
	
	printf("\nLevel order: \n");
	levelOrder(tree->root);
	
	printf("\nAfter Deleting 4: \n");
	deleteNode(tree->root, 4);
	preOrder(tree->root);
	
	return 0;
}
