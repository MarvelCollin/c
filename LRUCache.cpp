#include <stdio.h>
#include <stdlib.h>

#define capacity 3
#define size 100

struct Node {
	int key, value;
	Node *prev, *next;
};

Node *head = NULL, *tail = NULL;
Node *map[size];
int count = 0;

Node *createNode(int key, int value){
	Node *newNode = (Node*)malloc(sizeof(Node));

	*newNode = (Node){key, value, NULL, NULL};

	return newNode;
}

void removeNode(Node *node){
	if(node->prev != NULL){
		node->prev->next = node->next;
	} else {
		head = node->next;
	}

	if(node->next != NULL){
		node->next->prev = node->prev;
	} else {
		tail = node->prev;
	}

	node->prev = NULL;
	node->next = NULL;
}

void pushHead(Node *node){
	node->next = head;

	if(head != NULL){
		head->prev = node;
	}

	head = node;

	if(tail == NULL){
		tail = node;
	}
}

int get(int key){
	Node *node = map[key % size];

	if(node == NULL){
		return -1;
	}

	removeNode(node);
	pushHead(node);

	return node->value;
}

void put(int key, int value){
	Node *node = map[key % size];

	if(node != NULL){
		node->value = value;
		removeNode(node);
		pushHead(node);
		return;
	}

	if(count == capacity){
		Node *last = tail;
		map[last->key % size] = NULL;
		removeNode(last);
		free(last);
		count--;
	}

	Node *newNode = createNode(key, value);

	map[key % size] = newNode;
	pushHead(newNode);
	count++;
}

void printAll(){
	Node *curr = head;

	while(curr != NULL){
		printf("%d:%d ", curr->key, curr->value);
		curr = curr->next;
	}

	printf("\n");
}

int main(){
	for(int i = 0; i < size; i++){
		map[i] = NULL;
	}

	put(1, 10);
	put(2, 20);
	put(3, 30);

	printf("%d\n", get(1));

	put(4, 40);

	printf("%d\n", get(2));

	printAll();

	return 0;
}
