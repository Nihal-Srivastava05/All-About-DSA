#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct LinkedList
{
	struct node* head;
	struct node* tail;
};

struct LinkedList* createSingleLinkedList(int value)
{
	struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	list->head = (struct node*)malloc(sizeof(struct node));
	list->tail = (struct node*)malloc(sizeof(struct node));
	struct node* first = (struct node*)malloc(sizeof(struct node));
	first->data = value;
	first->next = NULL;
	list->head = first;
	list->tail = first;
	
	return list;
}

int isExist(struct LinkedList* list)
{
	if(list->head == NULL && list->tail == NULL) {
		return 0;
	}
	return 1;
}

int length(struct LinkedList* list)
{
	int len = 0;
	struct node* temp = list->head;
	while(temp->next != NULL) {
		len += 1;
		temp = temp->next;
	}
	
	return (len+1);
}

void insertLinkedList(struct LinkedList* list, int value, int location)
{
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current->data = value;
	int len = length(list);
	if(!isExist(list)) {
		printf("The Linked list does not exist");
	}
	else {
		if(location == 0) {
			current->next = list->head;
			list->head = current;
		}
		else if(location == len) {
			current->next = NULL;
			list->tail->next = current;
			list->tail = current;
		}
		else {
			struct node* temp = list->head;
			int i = 0;
			while(i < location - 1) {
				temp = temp->next;
				i += 1;
			}
			current->next = temp->next;
			temp->next = current;
		}
	}
}

void deletion(struct LinkedList* list, int location)
{
	if(!isExist(list)) {
		printf("The list does not exist.");
	}
	else {
		if(location == 0) {
			list->head = list->head->next;
			if(length(list) == 0) {
				list->tail = NULL;	
			}
		}
		else if(location == length(list)) {
			if(length(list) == 1) {
				list->head = NULL;
				list->tail = NULL;
			}
			struct node* temp = list->head;
			int i = 0;
			while(i < length(list) - 1) {
				temp = temp->next;
				i++;
			}
			list->tail = temp;
			temp->next = NULL;
		}
		else {
			struct node* temp = list->head;
			int i = 0;
			while(i < location - 1) {
				temp = temp->next;
				i++;
			}
			temp->next = temp->next->next;
		}
	}
}

void deleteLinkedList(struct LinkedList* list)
{
	list->head = NULL;
	list->tail = NULL;
}

void display(struct LinkedList* list)
{
	struct node* temp = list->head;
	if(isExist(list)){
		printf("%d ", temp->data);
		while(temp->next != NULL) {
			temp = temp->next;
			printf("%d ", temp->data);
		}
		printf("\n");
	} else {
		printf("Linked list does not exist.");
	}
	
}

int main()
{
	struct LinkedList* list = createSingleLinkedList(1);
	insertLinkedList(list, 2, 1);
	insertLinkedList(list, 3, 2);
	insertLinkedList(list, 4, 3);
	
	display(list);
	
	deletion(list, 0);
	display(list);
	
	deletion(list, 2);
	display(list);

	
	return 0;
}
