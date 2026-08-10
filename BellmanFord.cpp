#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Edge {
	int src, dst, cost;
};

void solve(Edge *edge, int v, int e, int startPoint){
	int cost[v];

	for(int i = 0; i < v; i++){
		cost[i] = INT_MAX;
	}

	cost[startPoint] = 0;

	for(int i = 0; i < v - 1; i++){
		for(int j = 0; j < e; j++){
			Edge currEdge = edge[j];

			if(cost[currEdge.src] != INT_MAX && cost[currEdge.src] + currEdge.cost < cost[currEdge.dst]){
				cost[currEdge.dst] = cost[currEdge.src] + currEdge.cost;
			}
		}
	}

	for(int j = 0; j < e; j++){
		Edge currEdge = edge[j];

		if(cost[currEdge.src] != INT_MAX && cost[currEdge.src] + currEdge.cost < cost[currEdge.dst]){
			printf("negative cycle\n");
			return;
		}
	}

	for(int i = 0; i < v; i++){
		printf("%d -> %d = %d\n", startPoint, i, cost[i]);
	}
}

int main(){
	int e = 8;
	int v = 5;

	Edge edge[e];
	edge[0] = (Edge){0,1,-1};
	edge[1] = (Edge){0,2,4};
	edge[2] = (Edge){1,2,3};
	edge[3] = (Edge){1,3,2};
	edge[4] = (Edge){1,4,2};
	edge[5] = (Edge){3,2,5};
	edge[6] = (Edge){3,1,1};
	edge[7] = (Edge){4,3,-3};

	solve(edge, v, e, 0);

	return 0;
}
