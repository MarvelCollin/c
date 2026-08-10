#include <stdio.h>
#include <stdbool.h>

#define v 5

int graph[v][v] = {
	{0, 1, 1, 1, 0},
	{1, 0, 1, 0, 0},
	{1, 1, 0, 0, 0},
	{1, 0, 0, 0, 1},
	{0, 0, 0, 1, 0},
};

int disc[v];
int low[v];
int parent[v];
bool isArticulation[v];
int timer;

void traverse(int curr){
	int child = 0;

	disc[curr] = low[curr] = timer++;

	for(int i = 0; i < v; i++){
		if(graph[curr][i]){
			if(disc[i] == -1){
				child++;
				parent[i] = curr;

				traverse(i);

				if(low[i] < low[curr]){
					low[curr] = low[i];
				}

				if(parent[curr] != -1 && low[i] >= disc[curr]){
					isArticulation[curr] = true;
				}

				if(parent[curr] == -1 && child > 1){
					isArticulation[curr] = true;
				}
			} else if(i != parent[curr] && disc[i] < low[curr]){
				low[curr] = disc[i];
			}
		}
	}
}

void solve(){
	timer = 0;

	for(int i = 0; i < v; i++){
		disc[i] = -1;
		low[i] = -1;
		parent[i] = -1;
		isArticulation[i] = false;
	}

	for(int i = 0; i < v; i++){
		if(disc[i] == -1){
			traverse(i);
		}
	}

	for(int i = 0; i < v; i++){
		if(isArticulation[i]){
			printf("%d ", i);
		}
	}

	printf("\n");
}

int main(){
	solve();

	return 0;
}
