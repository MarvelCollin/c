#include <stdio.h>

#define v 7

int parent[v];
int rankSet[v];

void makeSet(){
	for(int i = 0; i < v; i++){
		parent[i] = i;
		rankSet[i] = 0;
	}
}

int findParent(int index){
	if(parent[index] == index){
		return index;
	} else {
		parent[index] = findParent(parent[index]);
		return parent[index];
	}
}

void unionSet(int i1, int i2){
	int p1 = findParent(i1);
	int p2 = findParent(i2);

	if(p1 == p2){
		return;
	}

	if(rankSet[p1] < rankSet[p2]){
		parent[p1] = p2;
	} else if(rankSet[p1] > rankSet[p2]){
		parent[p2] = p1;
	} else {
		parent[p2] = p1;
		rankSet[p1]++;
	}
}

void solve(){
	makeSet();

	unionSet(0, 1);
	unionSet(1, 2);
	unionSet(3, 4);
	unionSet(5, 6);
	unionSet(4, 6);

	for(int i = 0; i < v; i++){
		printf("%d -> %d\n", i, findParent(i));
	}

	if(findParent(0) == findParent(2)){
		printf("0 and 2 connected\n");
	}

	if(findParent(0) != findParent(5)){
		printf("0 and 5 not connected\n");
	}
}

int main(){
	solve();

	return 0;
}
