#include <stdio.h>

#define n 8

int tree[n + 1];

void updateTree(int index, int value){
	index++;

	while(index <= n){
		tree[index] += value;
		index += index & (-index);
	}
}

int queryTree(int index){
	index++;

	int total = 0;

	while(index > 0){
		total += tree[index];
		index -= index & (-index);
	}

	return total;
}

int queryRange(int left, int right){
	if(left == 0){
		return queryTree(right);
	}

	return queryTree(right) - queryTree(left - 1);
}

int main(){
	int arr[n] = {3, 2, -1, 6, 5, 4, -3, 3};

	for(int i = 0; i <= n; i++){
		tree[i] = 0;
	}

	for(int i = 0; i < n; i++){
		updateTree(i, arr[i]);
	}

	printf("%d\n", queryRange(0, 5));

	updateTree(3, 4);

	printf("%d\n", queryRange(0, 5));

	return 0;
}
