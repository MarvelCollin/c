#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	Node *next;
};

Node *top = NULL;

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));

	*newNode = (Node){value, NULL};

	return newNode;
}

void push(int value){
	Node *newNode = createNode(value);

	newNode->next = top;
	top = newNode;
}

int pop(){
	if(top == NULL){
		printf("stack empty\n");
		return -1;
	}

	Node *temp = top;
	int value = temp->value;

	top = top->next;

	free(temp);

	return value;
}

int peek(){
	if(top == NULL){
		return -1;
	}

	return top->value;
}

void printAll(){
	Node *curr = top;

	while(curr != NULL){
		printf("%d ", curr->value);
		curr = curr->next;
	}

	printf("\n");
}

int main(){
	push(1);
	push(2);
	push(3);

	printAll();

	printf("%d\n", pop());
	printf("%d\n", peek());

	printAll();

	return 0;
}
