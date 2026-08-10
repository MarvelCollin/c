#include <stdio.h>
#include <stdbool.h>

#define v 4

int graph[v][v] = {
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{1, 0, 0, 1},
	{0, 0, 0, 0},
};

bool visited[v];
bool onStack[v];

bool traverse(int curr){
	visited[curr] = true;
	onStack[curr] = true;

	for(int i = 0; i < v; i++){
		if(graph[curr][i]){
			if(onStack[i]){
				return true;
			}

			if(!visited[i] && traverse(i)){
				return true;
			}
		}
	}

	onStack[curr] = false;

	return false;
}

void solve(){
	for(int i = 0; i < v; i++){
		visited[i] = false;
		onStack[i] = false;
	}

	for(int i = 0; i < v; i++){
		if(!visited[i] && traverse(i)){
			printf("cycle found\n");
			return;
		}
	}

	printf("no cycle\n");
}

int main(){
	solve();

	return 0;
}
