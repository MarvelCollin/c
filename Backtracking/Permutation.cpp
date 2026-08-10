#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

void solve(char *text, int start, int end){
	if(start == end){
		printf("%s\n", text);
		return;
	}

	for(int i = start; i <= end; i++){
		swap(&text[start], &text[i]);

		solve(text, start + 1, end);

		swap(&text[start], &text[i]);
	}
}

int main(){
	char text[] = "ABC";

	int len = strlen(text);

	solve(text, 0, len - 1);

	return 0;
}
