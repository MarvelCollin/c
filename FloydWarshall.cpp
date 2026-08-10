#include <stdio.h>

#define v 4
#define INF 99999

int graph[v][v] = {
	{0, 5, INF, 10},
	{INF, 0, 3, INF},
	{INF, INF, 0, 1},
	{INF, INF, INF, 0},
};

void printAll(int cost[v][v]){
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			if(cost[i][j] == INF){
				printf("INF ");
			} else {
				printf("%d ", cost[i][j]);
			}
		}
		printf("\n");
	}
}

void solve(){
	int cost[v][v];

	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			cost[i][j] = graph[i][j];
		}
	}

	for(int k = 0; k < v; k++){
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				if(cost[i][k] + cost[k][j] < cost[i][j]){
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	printAll(cost);
}

int main(){
	solve();

	return 0;
}
