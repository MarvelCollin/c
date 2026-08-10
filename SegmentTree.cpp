#include <stdio.h>

#define n 6

int arr[n] = {1, 3, 5, 7, 9, 11};
int tree[n * 4];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right){
	if(right < start || end < left){
		return 0;
	}

	if(left <= start && end <= right){
		return tree[node];
	}

	int mid = (start + end) / 2;

	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, int value){
	if(start == end){
		arr[index] = value;
		tree[node] = value;
		return;
	}

	int mid = (start + end) / 2;

	if(index <= mid){
		update(node * 2, start, mid, index, value);
	} else {
		update(node * 2 + 1, mid + 1, end, index, value);
	}

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main(){
	build(1, 0, n - 1);

	printf("%d\n", query(1, 0, n - 1, 1, 3));

	update(1, 0, n - 1, 1, 10);

	printf("%d\n", query(1, 0, n - 1, 1, 3));

	return 0;
}
