#include <stdio.h>
#include <string.h>

char digit[] = "0123456789ABCDEF";

void toBase(int number, int base){
	char result[64];
	int index = 0;

	if(number == 0){
		printf("0\n");
		return;
	}

	while(number > 0){
		result[index] = digit[number % base];
		index++;
		number /= base;
	}

	for(int i = index - 1; i >= 0; i--){
		printf("%c", result[i]);
	}

	printf("\n");
}

int toDecimal(char *text, int base){
	int len = strlen(text);
	int result = 0;

	for(int i = 0; i < len; i++){
		int value;

		if(text[i] >= '0' && text[i] <= '9'){
			value = text[i] - '0';
		} else {
			value = text[i] - 'A' + 10;
		}

		result = result * base + value;
	}

	return result;
}

int main(){
	toBase(255, 2);
	toBase(255, 8);
	toBase(255, 16);

	char text[] = "FF";

	printf("%d\n", toDecimal(text, 16));

	return 0;
}
