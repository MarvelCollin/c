#include <stdio.h>

int solve(int weight[], int value[], int n, int capacity){
	int table[n + 1][capacity + 1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= capacity; j++){
			if(i == 0 || j == 0){
				table[i][j] = 0;
			} else if(weight[i - 1] <= j){
				int taken = value[i - 1] + table[i - 1][j - weight[i - 1]];
				int skipped = table[i - 1][j];

				if(taken > skipped){
					table[i][j] = taken;
				} else {
					table[i][j] = skipped;
				}
			} else {
				table[i][j] = table[i - 1][j];
			}
		}
	}

	return table[n][capacity];
}

int main(){
	int weight[] = {1, 3, 4, 5};
	int value[] = {1, 4, 5, 7};
	int capacity = 7;

	int n = sizeof(weight) / sizeof(weight[0]);

	printf("%d\n", solve(weight, value, n, capacity));

	return 0;
}
