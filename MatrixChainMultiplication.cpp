#include <stdio.h>
#include <limits.h>

int solve(int dimension[], int n){
	int table[n][n];

	for(int i = 1; i < n; i++){
		table[i][i] = 0;
	}

	for(int len = 2; len < n; len++){
		for(int i = 1; i < n - len + 1; i++){
			int j = i + len - 1;

			table[i][j] = INT_MAX;

			for(int k = i; k < j; k++){
				int cost = table[i][k] + table[k + 1][j] + dimension[i - 1] * dimension[k] * dimension[j];

				if(cost < table[i][j]){
					table[i][j] = cost;
				}
			}
		}
	}

	return table[1][n - 1];
}

int main(){
	int dimension[] = {40, 20, 30, 10, 30};

	int n = sizeof(dimension) / sizeof(dimension[0]);

	printf("%d\n", solve(dimension, n));

	return 0;
}
