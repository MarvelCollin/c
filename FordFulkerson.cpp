#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define v 6

int graph[v][v] = {
	{0, 16, 13, 0, 0, 0},
	{0, 0, 10, 12, 0, 0},
	{0, 4, 0, 0, 14, 0},
	{0, 0, 9, 0, 0, 20},
	{0, 0, 0, 7, 0, 4},
	{0, 0, 0, 0, 0, 0},
};

bool findPath(int residual[v][v], int startPoint, int endPoint, int parent[v]){
	bool visited[v];
	int queue[v];
	int head = 0, tail = 0;

	for(int i = 0; i < v; i++){
		visited[i] = false;
		parent[i] = -1;
	}

	visited[startPoint] = true;
	queue[tail++] = startPoint;

	while(head < tail){
		int curr = queue[head++];

		for(int i = 0; i < v; i++){
			if(!visited[i] && residual[curr][i] > 0){
				visited[i] = true;
				parent[i] = curr;
				queue[tail++] = i;
			}
		}
	}

	return visited[endPoint];
}

void solve(int startPoint, int endPoint){
	int residual[v][v];
	int parent[v];
	int maxFlow = 0;

	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			residual[i][j] = graph[i][j];
		}
	}

	while(findPath(residual, startPoint, endPoint, parent)){
		int pathFlow = INT_MAX;

		for(int i = endPoint; i != startPoint; i = parent[i]){
			if(residual[parent[i]][i] < pathFlow){
				pathFlow = residual[parent[i]][i];
			}
		}

		for(int i = endPoint; i != startPoint; i = parent[i]){
			residual[parent[i]][i] -= pathFlow;
			residual[i][parent[i]] += pathFlow;
		}

		maxFlow += pathFlow;
	}

	printf("%d\n", maxFlow);
}

int main(){
	solve(0, v - 1);

	return 0;
}
