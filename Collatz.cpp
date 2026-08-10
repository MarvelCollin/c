#include <stdio.h>

int solve(int number){
	int step = 0;

	while(number != 1){
		printf("%d ", number);

		if(number % 2 == 0){
			number /= 2;
		} else {
			number = number * 3 + 1;
		}

		step++;
	}

	printf("%d\n", number);

	return step;
}

int main(){
	printf("%d\n", solve(27));

	return 0;
}
