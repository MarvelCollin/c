#include <stdio.h>
#include <string.h>

int findMin(int a, int b, int c){
	int minimum = a;

	if(b < minimum){
		minimum = b;
	}

	if(c < minimum){
		minimum = c;
	}

	return minimum;
}

int solve(char *word1, char *word2){
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	int cost[len1 + 1][len2 + 1];

	for(int i = 0; i <= len1; i++){
		cost[i][0] = i;
	}

	for(int j = 0; j <= len2; j++){
		cost[0][j] = j;
	}

	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			if(word1[i - 1] == word2[j - 1]){
				cost[i][j] = cost[i - 1][j - 1];
			} else {
				cost[i][j] = 1 + findMin(cost[i - 1][j], cost[i][j - 1], cost[i - 1][j - 1]);
			}
		}
	}

	return cost[len1][len2];
}

int main(){
	char word1[] = "kitten";
	char word2[] = "sitting";

	printf("%d\n", solve(word1, word2));

	return 0;
}
