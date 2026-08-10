#include <stdio.h>
#include <stdbool.h>

#define limit 50

bool isPrime[limit + 1];

void solve(){
	for(int i = 0; i <= limit; i++){
		isPrime[i] = true;
	}

	isPrime[0] = false;
	isPrime[1] = false;

	for(int i = 2; i * i <= limit; i++){
		if(isPrime[i]){
			for(int j = i * i; j <= limit; j += i){
				isPrime[j] = false;
			}
		}
	}

	for(int i = 2; i <= limit; i++){
		if(isPrime[i]){
			printf("%d ", i);
		}
	}

	printf("\n");
}

int main(){
	solve();

	return 0;
}
