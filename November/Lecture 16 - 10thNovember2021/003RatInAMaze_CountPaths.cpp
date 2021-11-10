/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to
	
	> count the number of paths that exist between src and dst

such at each step the rat can only move in the right or down direction.

Constraint 

 1 <= m, n < 10

Example 
	Input : 

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}
	
	Output : 3
	
*/

#include<iostream>

using namespace std;

int countPaths(char maze[][10], int m, int n, int i, int j) {
	// base case

	if(i == m-1 and j == n-1) {
		// you've reached the destination
		return 1;
	}

	// additional base case to handle situation if rat goes outside the maze

	if(i == m or j == n) {
		// you've gone beyond the bounardaries of the maze
		return 0;
	}

	if(maze[i][j] == 'X') {
		// you cannot go from a blocked cell to the destination
		return 0;
	}

	// if(i == m-1) {
	// 	// you're at a cell in the last row, you've no option but to move right
	// 	return countPaths(maze, m, n, i, j+1);
	// }

	// if(j == n-1) {
	// 	// you're at a cell in the last column, so you've no option but to move down
	// 	return countPaths(maze, m, n, i+1, j);
	// }

	// you're at a cell from where you've an option to move right or down

	int X = countPaths(maze, m, n, i, j+1); // move right
	int Y = countPaths(maze, m, n, i+1, j); // move down

	return X + Y;

}


int main() {

	char maze[][10] = {"0000",
	                   "00X0",
	                   "000X",
	                   "0X00"};
	int m = 4;
	int n = 4;

	cout << countPaths(maze, m, n, 0, 0) << endl;

	return 0;
}


