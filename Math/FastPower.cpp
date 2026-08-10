#include <stdio.h>

long long fastPower(long long base, long long exponent){
	long long result = 1;

	while(exponent > 0){
		if(exponent % 2 == 1){
			result *= base;
		}

		base *= base;
		exponent /= 2;
	}

	return result;
}

long long fastPowerMod(long long base, long long exponent, long long mod){
	long long result = 1;

	base %= mod;

	while(exponent > 0){
		if(exponent % 2 == 1){
			result = result * base % mod;
		}

		base = base * base % mod;
		exponent /= 2;
	}

	return result;
}

int main(){
	printf("%lld\n", fastPower(2, 20));
	printf("%lld\n", fastPowerMod(2, 100, 1000000007));

	return 0;
}
