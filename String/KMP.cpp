#include <stdio.h>
#include <string.h>

void buildTable(char *pattern, int len, int *table){
	table[0] = 0;

	int prefix = 0;
	int i = 1;

	while(i < len){
		if(pattern[i] == pattern[prefix]){
			prefix++;
			table[i] = prefix;
			i++;
		} else if(prefix > 0){
			prefix = table[prefix - 1];
		} else {
			table[i] = 0;
			i++;
		}
	}
}

void solve(char *text, char *pattern){
	int lenText = strlen(text);
	int lenPattern = strlen(pattern);
	int table[lenPattern];

	buildTable(pattern, lenPattern, table);

	int i = 0, j = 0;

	while(i < lenText){
		if(text[i] == pattern[j]){
			i++;
			j++;

			if(j == lenPattern){
				printf("found at %d\n", i - j);
				j = table[j - 1];
			}
		} else if(j > 0){
			j = table[j - 1];
		} else {
			i++;
		}
	}
}

int main(){
	char text[] = "ababcabcabababd";
	char pattern[] = "ababd";

	solve(text, pattern);

	return 0;
}
