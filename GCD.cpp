#include <stdio.h>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}

	return gcd(b, a % b);
}

int lcm(int a, int b){
	return a / gcd(a, b) * b;
}

int main(){
	int a = 48;
	int b = 18;

	printf("%d\n", gcd(a, b));
	printf("%d\n", lcm(a, b));

	return 0;
}
