#include <stdio.h>
#include <stdbool.h>

#define n 6

int board[n][n];

int moveY[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int moveX[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void printBoard(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%3d ", board[i][j]);
		}
		printf("\n");
	}
}

bool solve(int y, int x, int step){
	if(step == n * n){
		return true;
	}

	for(int i = 0; i < 8; i++){
		int newY = y + moveY[i];
		int newX = x + moveX[i];

		if(newY < 0 || newY >= n || newX < 0 || newX >= n){
			continue;
		}

		if(board[newY][newX] != -1){
			continue;
		}

		board[newY][newX] = step;

		if(solve(newY, newX, step + 1)){
			return true;
		}

		board[newY][newX] = -1;
	}

	return false;
}

int main(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			board[i][j] = -1;
		}
	}

	board[0][0] = 0;

	if(solve(0, 0, 1)){
		printBoard();
	} else {
		printf("no solution\n");
	}

	return 0;
}
