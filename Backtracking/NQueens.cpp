#include <stdio.h>
#include <stdbool.h>

#define n 8

int board[n];

bool isSafe(int row, int col){
	for(int i = 0; i < row; i++){
		if(board[i] == col){
			return false;
		}

		if(row - i == col - board[i] || row - i == board[i] - col){
			return false;
		}
	}

	return true;
}

void printBoard(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i] == j){
				printf("Q ");
			} else {
				printf(". ");
			}
		}
		printf("\n");
	}
}

bool solve(int row){
	if(row == n){
		return true;
	}

	for(int col = 0; col < n; col++){
		if(isSafe(row, col)){
			board[row] = col;

			if(solve(row + 1)){
				return true;
			}

			board[row] = -1;
		}
	}

	return false;
}

int main(){
	for(int i = 0; i < n; i++){
		board[i] = -1;
	}

	if(solve(0)){
		printBoard();
	} else {
		printf("no solution\n");
	}

	return 0;
}
