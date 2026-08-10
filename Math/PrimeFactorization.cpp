#include <stdio.h>

void solve(int number){
	while(number % 2 == 0){
		printf("2 ");
		number /= 2;
	}

	for(int i = 3; i * i <= number; i += 2){
		while(number % i == 0){
			printf("%d ", i);
			number /= i;
		}
	}

	if(number > 1){
		printf("%d ", number);
	}

	printf("\n");
}

int main(){
	solve(315);
	solve(1024);
	solve(97);

	return 0;
}
