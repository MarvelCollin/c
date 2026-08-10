#include <stdio.h>
#include <string.h>

#define alphabet 256

void buildBadChar(char *pattern, int len, int *badChar){
	for(int i = 0; i < alphabet; i++){
		badChar[i] = -1;
	}

	for(int i = 0; i < len; i++){
		badChar[(int)pattern[i]] = i;
	}
}

void solve(char *text, char *pattern){
	int lenText = strlen(text);
	int lenPattern = strlen(pattern);
	int badChar[alphabet];

	buildBadChar(pattern, lenPattern, badChar);

	int shift = 0;

	while(shift <= lenText - lenPattern){
		int j = lenPattern - 1;

		while(j >= 0 && pattern[j] == text[shift + j]){
			j--;
		}

		if(j < 0){
			printf("found at %d\n", shift);

			if(shift + lenPattern < lenText){
				shift += lenPattern - badChar[(int)text[shift + lenPattern]];
			} else {
				shift += 1;
			}
		} else {
			int jump = j - badChar[(int)text[shift + j]];

			if(jump < 1){
				jump = 1;
			}

			shift += jump;
		}
	}
}

int main(){
	char text[] = "ABAAABCDABAAABCD";
	char pattern[] = "ABC";

	solve(text, pattern);

	return 0;
}
