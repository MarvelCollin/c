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

void solve(int startPoint){
	bool visited[v];
	int queue[v];
	int head = 0, tail = 0;

	for(int i = 0; i < v; i++){
		visited[i] = false;
	}

	visited[startPoint] = true;
	queue[tail++] = startPoint;

	while(head < tail){
		int curr = queue[head++];

		printf("%d ", curr);

		for(int i = 0; i < v; i++){
			if(graph[curr][i] && !visited[i]){
				visited[i] = true;
				queue[tail++] = i;
			}
		}
	}

	printf("\n");
}

int main(){
	solve(0);

	return 0;
}
