#include <stdio.h>
#include <limits.h>

int solve(int coin[], int n, int target){
	int table[target + 1];

	table[0] = 0;

	for(int i = 1; i <= target; i++){
		table[i] = INT_MAX;

		for(int j = 0; j < n; j++){
			if(coin[j] <= i && table[i - coin[j]] != INT_MAX && table[i - coin[j]] + 1 < table[i]){
				table[i] = table[i - coin[j]] + 1;
			}
		}
	}

	return table[target];
}

int main(){
	int coin[] = {1, 5, 6, 9};
	int target = 11;

	int n = sizeof(coin) / sizeof(coin[0]);

	int result = solve(coin, n, target);

	if(result == INT_MAX){
		printf("not possible\n");
	} else {
		printf("%d\n", result);
	}

	return 0;
}
