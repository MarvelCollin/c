#include <stdio.h>

int solve(int arr[], int len){
	int table[len];
	int best = 0;

	for(int i = 0; i < len; i++){
		table[i] = 1;

		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i] && table[j] + 1 > table[i]){
				table[i] = table[j] + 1;
			}
		}

		if(table[i] > best){
			best = table[i];
		}
	}

	return best;
}

int main(){
	int array[] = {10, 22, 9, 33, 21, 50, 41, 60};

	int len = sizeof(array) / sizeof(array[0]);

	printf("%d\n", solve(array, len));

	return 0;
}
