#include <stdio.h>
#include <string.h>

#define base 256
#define mod 101

void solve(char *text, char *pattern){
	int lenText = strlen(text);
	int lenPattern = strlen(pattern);

	if(lenPattern > lenText){
		return;
	}

	int power = 1;

	for(int i = 0; i < lenPattern - 1; i++){
		power = (power * base) % mod;
	}

	int hashText = 0, hashPattern = 0;

	for(int i = 0; i < lenPattern; i++){
		hashPattern = (base * hashPattern + pattern[i]) % mod;
		hashText = (base * hashText + text[i]) % mod;
	}

	for(int i = 0; i <= lenText - lenPattern; i++){
		if(hashText == hashPattern){
			int j = 0;

			while(j < lenPattern && text[i + j] == pattern[j]){
				j++;
			}

			if(j == lenPattern){
				printf("found at %d\n", i);
			}
		}

		if(i < lenText - lenPattern){
			hashText = (base * (hashText - text[i] * power) + text[i + lenPattern]) % mod;

			if(hashText < 0){
				hashText += mod;
			}
		}
	}
}

int main(){
	char text[] = "geeksforgeeks";
	char pattern[] = "eek";

	solve(text, pattern);

	return 0;
}
