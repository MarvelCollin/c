#include <stdio.h>

#define v 6

int graph[v][v] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{1, 0, 1, 0, 0, 0},
};

void solve(){
	int indegree[v];
	int queue[v];
	int head = 0, tail = 0;
	int counter = 0;

	for(int i = 0; i < v; i++){
		indegree[i] = 0;
	}

	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			if(graph[i][j]){
				indegree[j]++;
			}
		}
	}

	for(int i = 0; i < v; i++){
		if(indegree[i] == 0){
			queue[tail++] = i;
		}
	}

	while(head < tail){
		int curr = queue[head++];
		counter++;

		printf("%d ", curr);

		for(int i = 0; i < v; i++){
			if(graph[curr][i]){
				indegree[i]--;

				if(indegree[i] == 0){
					queue[tail++] = i;
				}
			}
		}
	}

	printf("\n");

	if(counter != v){
		printf("graph has cycle\n");
	}
}

int main(){
	solve();

	return 0;
}
