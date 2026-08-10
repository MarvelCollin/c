#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	Node *prev, *next;
};

Node *head = NULL, *tail = NULL;

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));

	*newNode = (Node){value, NULL, NULL};

	return newNode;
}

void pushHead(int value){
	Node *newNode = createNode(value);

	if(head == NULL){
		head = tail = newNode;
		return;
	}

	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

void pushTail(int value){
	Node *newNode = createNode(value);

	if(tail == NULL){
		head = tail = newNode;
		return;
	}

	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
}

void popHead(){
	if(head == NULL){
		return;
	}

	Node *temp = head;

	if(head == tail){
		head = tail = NULL;
	} else {
		head = head->next;
		head->prev = NULL;
	}

	free(temp);
}

void popTail(){
	if(tail == NULL){
		return;
	}

	Node *temp = tail;

	if(head == tail){
		head = tail = NULL;
	} else {
		tail = tail->prev;
		tail->next = NULL;
	}

	free(temp);
}

void printAll(){
	Node *curr = head;

	while(curr != NULL){
		printf("%d ", curr->value);
		curr = curr->next;
	}

	printf("\n");
}

int main(){
	pushHead(2);
	pushHead(1);
	pushTail(3);
	pushTail(4);

	printAll();

	popHead();
	popTail();

	printAll();

	return 0;
}
