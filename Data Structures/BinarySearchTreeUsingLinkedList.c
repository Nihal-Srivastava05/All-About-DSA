#include<stdlib.h>
#include<stdio.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct BST {
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

struct node* createNode(int value)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->right = NULL;
    temp->left = NULL;

    return temp;
}

struct BST* createTree(int value) {
	struct BST* tree = (struct BST*)malloc(sizeof(struct BST));
	tree->root = (struct node*)malloc(sizeof(struct node));;
	tree->root = createNode(value);
	
	return tree;
}

int searchBST(struct node* root, int value) {
	if(root == NULL) {
		return -1;
	}
	else if(root->data == value) {
		return root;
	}
	else if(root->data < value) {
		searchBST(root->right, value);
	}
	else {
		searchBST(root->left, value);
	}
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
		if(temp->data != -1) {
			printf("%d ", temp->data);
		}
	}
}

struct node* insertNode(struct node* root, int value) {
	if(root == NULL) {
		struct node* current = createNode(value);
		root = current;
		
	}
	else if(value <= root->data){
		root->left = insertNode(root->left, value);
	}
	else {
		root->right = insertNode(root->right, value);
	}
	
	return root;
}

struct node* deleteNode(struct node* root, int value) {
	if(root == NULL) {
		return;
	}
	else if(value < root->data) {
		root->left = deleteNode(root->left, value);
	}
	else if(value > root->data) {
		root->right = deleteNode(root->right, value);
	}
	else {
		if(root->left != NULL && root->right != NULL) {
			struct node* temp = root->right;
			while(temp->left != NULL) {
				temp = temp->left;
			}
			root->data = temp->data;
			temp->data = -1;
			temp = NULL;
		}
		else if(root->left != NULL) {
			root = root->left;
		}
		else if(root->right != NULL) {
			root = root->right;
		}
		else {
			root = NULL;
		}
	}
	
	return root;
}

void deleteTree(struct node* root) {
	root = NULL;
}

int findMin(struct node* root) {
	struct node* temp = root;
	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp->data;
}

int findMax(struct node* root) {
	struct node* temp = root;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp->data;
}

int main()
{
	int n, ele, i;
	scanf("%d", &n);
	scanf("%d", &ele);
	struct BST* tree = createTree(ele);
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
	
	struct node* temp = searchBST(tree->root, 4);
	printf("\n%d\n", temp->data);
	
	printf("MAX: %d\n", findMax(tree->root));
	printf("MIN: %d\n", findMin(tree->root));
	
	deleteNode(tree->root, 5);
	levelOrder(tree->root);
	
	return 0;
}
