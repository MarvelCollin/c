#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	char color;
	Node *left, *right, *parent;
};

Node *root = NULL;

Node *createNode(int key){
	Node *newNode = (Node*)malloc(sizeof(Node));

	*newNode = (Node){key, 'R', NULL, NULL, NULL};

	return newNode;
}

void leftRotate(Node *node){
	Node *child = node->right;

	node->right = child->left;

	if(child->left != NULL){
		child->left->parent = node;
	}

	child->parent = node->parent;

	if(node->parent == NULL){
		root = child;
	} else if(node == node->parent->left){
		node->parent->left = child;
	} else {
		node->parent->right = child;
	}

	child->left = node;
	node->parent = child;
}

void rightRotate(Node *node){
	Node *child = node->left;

	node->left = child->right;

	if(child->right != NULL){
		child->right->parent = node;
	}

	child->parent = node->parent;

	if(node->parent == NULL){
		root = child;
	} else if(node == node->parent->right){
		node->parent->right = child;
	} else {
		node->parent->left = child;
	}

	child->right = node;
	node->parent = child;
}

void insertFix(Node *node){
	while(node->parent != NULL && node->parent->color == 'R'){
		Node *parent = node->parent;
		Node *grand = parent->parent;

		if(grand == NULL){
			break;
		}

		if(parent == grand->left){
			Node *uncle = grand->right;

			if(uncle != NULL && uncle->color == 'R'){
				parent->color = 'B';
				uncle->color = 'B';
				grand->color = 'R';
				node = grand;
			} else {
				if(node == parent->right){
					node = parent;
					leftRotate(node);
					parent = node->parent;
					grand = parent->parent;
				}

				parent->color = 'B';
				grand->color = 'R';
				rightRotate(grand);
			}
		} else {
			Node *uncle = grand->left;

			if(uncle != NULL && uncle->color == 'R'){
				parent->color = 'B';
				uncle->color = 'B';
				grand->color = 'R';
				node = grand;
			} else {
				if(node == parent->left){
					node = parent;
					rightRotate(node);
					parent = node->parent;
					grand = parent->parent;
				}

				parent->color = 'B';
				grand->color = 'R';
				leftRotate(grand);
			}
		}
	}

	root->color = 'B';
}

void insert(int key){
	Node *newNode = createNode(key);
	Node *curr = root;
	Node *parent = NULL;

	while(curr != NULL){
		parent = curr;

		if(key < curr->key){
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}

	newNode->parent = parent;

	if(parent == NULL){
		root = newNode;
	} else if(key < parent->key){
		parent->left = newNode;
	} else {
		parent->right = newNode;
	}

	insertFix(newNode);
}

void inorder(Node *node){
	if(node == NULL){
		return;
	}

	inorder(node->left);

	printf("%d%c ", node->key, node->color);

	inorder(node->right);
}

int main(){
	int data[] = {7, 3, 18, 10, 22, 8, 11, 26};

	int len = sizeof(data) / sizeof(data[0]);

	for(int i = 0; i < len; i++){
		insert(data[i]);
	}

	inorder(root);

	printf("\n");
	printf("root %d\n", root->key);

	return 0;
}
