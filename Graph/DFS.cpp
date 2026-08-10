#include <stdio.h>
#include <stdbool.h>

#define v 6

int graph[v][v] = {
	{0, 1, 1, 0, 0, 0},
	{1, 0, 0, 1, 1, 0},
	{1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 1, 1},
	{0, 1, 1, 1, 0, 1},
	{0, 0, 0, 1, 1, 0},
};

bool visited[v];

void traverse(int curr){
	visited[curr] = true;

	printf("%d ", curr);

	for(int i = 0; i < v; i++){
		if(graph[curr][i] && !visited[i]){
			traverse(i);
		}
	}
}

void solve(int startPoint){
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}

	traverse(startPoint);

	printf("\n");
}

int main(){
	solve(0);

	return 0;
}
