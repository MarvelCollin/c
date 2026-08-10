#include <stdio.h>
#include <string.h>

void solve(char *text){
	int len = strlen(text);
	int lenBuild = len * 2 + 1;
	char build[lenBuild + 1];

	for(int i = 0; i < lenBuild; i++){
		if(i % 2 == 0){
			build[i] = '#';
		} else {
			build[i] = text[i / 2];
		}
	}

	build[lenBuild] = '\0';

	int radius[lenBuild];
	int center = 0, right = 0;

	for(int i = 0; i < lenBuild; i++){
		radius[i] = 0;

		if(i < right){
			int mirror = center * 2 - i;

			if(radius[mirror] < right - i){
				radius[i] = radius[mirror];
			} else {
				radius[i] = right - i;
			}
		}

		while(i - radius[i] - 1 >= 0 && i + radius[i] + 1 < lenBuild && build[i - radius[i] - 1] == build[i + radius[i] + 1]){
			radius[i]++;
		}

		if(i + radius[i] > right){
			center = i;
			right = i + radius[i];
		}
	}

	int best = 0, bestCenter = 0;

	for(int i = 0; i < lenBuild; i++){
		if(radius[i] > best){
			best = radius[i];
			bestCenter = i;
		}
	}

	int start = (bestCenter - best) / 2;

	for(int i = start; i < start + best; i++){
		printf("%c", text[i]);
	}

	printf("\n");
}

int main(){
	char text[] = "babadada";

	solve(text);

	return 0;
}
