#include <stdio.h>
#include <string.h>

void solve(char *word1, char *word2){
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	int table[len1 + 1][len2 + 1];

	for(int i = 0; i <= len1; i++){
		for(int j = 0; j <= len2; j++){
			if(i == 0 || j == 0){
				table[i][j] = 0;
			} else if(word1[i - 1] == word2[j - 1]){
				table[i][j] = table[i - 1][j - 1] + 1;
			} else if(table[i - 1][j] > table[i][j - 1]){
				table[i][j] = table[i - 1][j];
			} else {
				table[i][j] = table[i][j - 1];
			}
		}
	}

	int len = table[len1][len2];
	char result[len + 1];

	result[len] = '\0';

	int i = len1, j = len2, index = len - 1;

	while(i > 0 && j > 0){
		if(word1[i - 1] == word2[j - 1]){
			result[index] = word1[i - 1];
			index--;
			i--;
			j--;
		} else if(table[i - 1][j] > table[i][j - 1]){
			i--;
		} else {
			j--;
		}
	}

	printf("%d %s\n", len, result);
}

int main(){
	char word1[] = "AGGTAB";
	char word2[] = "GXTXAYB";

	solve(word1, word2);

	return 0;
}
