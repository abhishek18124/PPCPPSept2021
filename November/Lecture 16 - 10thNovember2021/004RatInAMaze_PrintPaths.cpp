/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to
	
	> generate all the paths from src to dst

such at each step the rat can only move in the right or down direction.

Constraint 

 1 <= m, n < 10

Example 
	Input : 

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}
	
	Output :

	       {"1100", {"1000", {"1000",
            "0100",	 "1100",  "1000",
            "0110",  "0110",  "1110",
            "0011"}  "0011"}  "0011"}

*/

#include<iostream>

using namespace std;

void printPaths(char maze[][10], char soln[][10], int m, int n, int i, int j) {
	// base case
	if(i == m-1 and j == n-1) {
		// you've reached the destination i.e you've must already built the soln so just print it
		soln[i][j] = '1';
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		soln[i][j] = '0';
		return;
	}

	// additional base case to handle situation if rat goes outside the maze

	if(i == m or j == n) {
		// you've gone beyond the bounardaries of the maze
		return;
	}

	if(maze[i][j] == 'X') {
		// you cannot go from a blocked cell to the destination
		return;
	}

	// if(i == m-1) {
	// 	// you're at a cell in the last row, you've no option but to move right
	// 	soln[i][j] = '1';
	// 	printPaths(maze, soln, m, n, i, j+1);
	// 	soln[i][j] = '0'; // backtracking
	// 	return;
	// }

	// if(j == n-1) {
	// 	// you're at a cell in the last column, so you've no option but to move down
	// 	soln[i][j] = '1';
	// 	printPaths(maze, soln, m, n, i+1, j);
	// 	soln[i][j] = '0'; // backtracking
	// 	return;
	// }

	// you're at a cell from where you've an option to move right or down

	soln[i][j] = '1';
	printPaths(maze, soln, m, n, i, j+1); // move right
	printPaths(maze, soln, m, n, i+1, j); // move down
	soln[i][j] = '0'; // backtracking

	return;

}


int main() {

	char maze[][10] = {"0X00",
	           		   "0XX0",
	                   "00XX",
	                   "00X0"};

	char soln[][10] = {"0000",
	                   "0000",
	                   "0000",
	                   "0001"};
	int m = 4;
	int n = 4;

	printPaths(maze, soln, m, n, 0, 0);

	return 0;
}


