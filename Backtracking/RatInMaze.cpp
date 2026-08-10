#include <stdio.h>
#include <stdbool.h>

#define n 6

char maze[n][n + 1] = {
	"S....#",
	".##..#",
	"...#..",
	"##...#",
	"#..#..",
	"#....E",
};

int moveY[4] = {-1, 0, 1, 0};
int moveX[4] = {0, 1, 0, -1};

bool visited[n][n];

void printMaze(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

bool solve(int y, int x){
	if(y < 0 || y >= n || x < 0 || x >= n){
		return false;
	}

	if(maze[y][x] == '#' || visited[y][x]){
		return false;
	}

	visited[y][x] = true;

	if(maze[y][x] == 'E'){
		return true;
	}

	for(int i = 0; i < 4; i++){
		if(solve(y + moveY[i], x + moveX[i])){
			if(maze[y][x] != 'S'){
				maze[y][x] = '*';
			}

			return true;
		}
	}

	visited[y][x] = false;

	return false;
}

int main(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			visited[i][j] = false;
		}
	}

	if(solve(0, 0)){
		printMaze();
	} else {
		printf("no path\n");
	}

	return 0;
}
