#include <stdio.h>

#define size 5

int queue[size];
int head = 0, tail = -1, count = 0;

void enqueue(int value){
	if(count == size){
		printf("queue full\n");
		return;
	}

	tail = (tail + 1) % size;
	queue[tail] = value;
	count++;
}

int dequeue(){
	if(count == 0){
		printf("queue empty\n");
		return -1;
	}

	int value = queue[head];

	head = (head + 1) % size;
	count--;

	return value;
}

void printAll(){
	for(int i = 0; i < count; i++){
		printf("%d ", queue[(head + i) % size]);
	}

	printf("\n");
}

int main(){
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);

	printAll();

	printf("%d\n", dequeue());
	printf("%d\n", dequeue());

	enqueue(6);
	enqueue(7);

	printAll();

	return 0;
}
