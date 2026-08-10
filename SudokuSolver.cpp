#include <stdio.h>
#include <stdbool.h>

#define n 9

int board[n][n] = {
	{5, 3, 0, 0, 7, 0, 0, 0, 0},
	{6, 0, 0, 1, 9, 5, 0, 0, 0},
	{0, 9, 8, 0, 0, 0, 0, 6, 0},
	{8, 0, 0, 0, 6, 0, 0, 0, 3},
	{4, 0, 0, 8, 0, 3, 0, 0, 1},
	{7, 0, 0, 0, 2, 0, 0, 0, 6},
	{0, 6, 0, 0, 0, 0, 2, 8, 0},
	{0, 0, 0, 4, 1, 9, 0, 0, 5},
	{0, 0, 0, 0, 8, 0, 0, 7, 9},
};

bool isSafe(int row, int col, int value){
	for(int i = 0; i < n; i++){
		if(board[row][i] == value || board[i][col] == value){
			return false;
		}
	}

	int startRow = row - row % 3;
	int startCol = col - col % 3;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[startRow + i][startCol + j] == value){
				return false;
			}
		}
	}

	return true;
}

void printBoard(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

bool solve(){
	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			if(board[row][col] == 0){
				for(int value = 1; value <= 9; value++){
					if(isSafe(row, col, value)){
						board[row][col] = value;

						if(solve()){
							return true;
						}

						board[row][col] = 0;
					}
				}

				return false;
			}
		}
	}

	return true;
}

int main(){
	if(solve()){
		printBoard();
	} else {
		printf("no solution\n");
	}

	return 0;
}
