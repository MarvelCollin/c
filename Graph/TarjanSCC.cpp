#include <stdio.h>
#include <stdbool.h>

#define v 5

int graph[v][v] = {
	{0, 0, 1, 1, 0},
	{1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0},
};

int disc[v];
int low[v];
int stackList[v];
bool onStack[v];
int timer, top;

void traverse(int curr){
	disc[curr] = low[curr] = timer++;
	stackList[top++] = curr;
	onStack[curr] = true;

	for(int i = 0; i < v; i++){
		if(graph[curr][i]){
			if(disc[i] == -1){
				traverse(i);

				if(low[i] < low[curr]){
					low[curr] = low[i];
				}
			} else if(onStack[i] && disc[i] < low[curr]){
				low[curr] = disc[i];
			}
		}
	}

	if(low[curr] == disc[curr]){
		while(true){
			int node = stackList[--top];
			onStack[node] = false;

			printf("%d ", node);

			if(node == curr){
				break;
			}
		}

		printf("\n");
	}
}

void solve(){
	timer = 0;
	top = 0;

	for(int i = 0; i < v; i++){
		disc[i] = -1;
		low[i] = -1;
		onStack[i] = false;
	}

	for(int i = 0; i < v; i++){
		if(disc[i] == -1){
			traverse(i);
		}
	}
}

int main(){
	solve();

	return 0;
}
