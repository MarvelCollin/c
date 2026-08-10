#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define degree 3

struct Node {
	int key[degree * 2 - 1];
	Node *child[degree * 2];
	int count;
	bool isLeaf;
};

Node *root = NULL;

Node *createNode(bool isLeaf){
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->count = 0;
	newNode->isLeaf = isLeaf;

	for(int i = 0; i < degree * 2; i++){
		newNode->child[i] = NULL;
	}

	return newNode;
}

void splitChild(Node *parent, int index){
	Node *full = parent->child[index];
	Node *newNode = createNode(full->isLeaf);

	newNode->count = degree - 1;

	for(int i = 0; i < degree - 1; i++){
		newNode->key[i] = full->key[i + degree];
	}

	if(!full->isLeaf){
		for(int i = 0; i < degree; i++){
			newNode->child[i] = full->child[i + degree];
		}
	}

	full->count = degree - 1;

	for(int i = parent->count; i > index; i--){
		parent->child[i + 1] = parent->child[i];
	}

	parent->child[index + 1] = newNode;

	for(int i = parent->count - 1; i >= index; i--){
		parent->key[i + 1] = parent->key[i];
	}

	parent->key[index] = full->key[degree - 1];
	parent->count++;
}

void insertNonFull(Node *node, int key){
	int i = node->count - 1;

	if(node->isLeaf){
		while(i >= 0 && node->key[i] > key){
			node->key[i + 1] = node->key[i];
			i--;
		}

		node->key[i + 1] = key;
		node->count++;
	} else {
		while(i >= 0 && node->key[i] > key){
			i--;
		}

		i++;

		if(node->child[i]->count == degree * 2 - 1){
			splitChild(node, i);

			if(node->key[i] < key){
				i++;
			}
		}

		insertNonFull(node->child[i], key);
	}
}

void insert(int key){
	if(root == NULL){
		root = createNode(true);
		root->key[0] = key;
		root->count = 1;
		return;
	}

	if(root->count == degree * 2 - 1){
		Node *newRoot = createNode(false);

		newRoot->child[0] = root;

		splitChild(newRoot, 0);

		int i = 0;

		if(newRoot->key[0] < key){
			i++;
		}

		insertNonFull(newRoot->child[i], key);

		root = newRoot;
	} else {
		insertNonFull(root, key);
	}
}

void traverse(Node *node){
	if(node == NULL){
		return;
	}

	int i;

	for(i = 0; i < node->count; i++){
		if(!node->isLeaf){
			traverse(node->child[i]);
		}

		printf("%d ", node->key[i]);
	}

	if(!node->isLeaf){
		traverse(node->child[i]);
	}
}

bool search(Node *node, int key){
	if(node == NULL){
		return false;
	}

	int i = 0;

	while(i < node->count && key > node->key[i]){
		i++;
	}

	if(i < node->count && node->key[i] == key){
		return true;
	}

	if(node->isLeaf){
		return false;
	}

	return search(node->child[i], key);
}

int main(){
	int data[] = {10, 20, 5, 6, 12, 30, 7, 17};

	int len = sizeof(data) / sizeof(data[0]);

	for(int i = 0; i < len; i++){
		insert(data[i]);
	}

	traverse(root);

	printf("\n");
	printf("%d\n", search(root, 12));
	printf("%d\n", search(root, 15));

	return 0;
}
