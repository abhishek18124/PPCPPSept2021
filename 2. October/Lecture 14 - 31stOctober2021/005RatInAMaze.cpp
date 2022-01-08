/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to
	a) check if there exists a path from src to dst
	b) print all the paths from src to dst (assume last cell is not blocked)
such at each step the rat can only move in the right or down direction.

Constraint 

 1 <= m, n <= 10

Example 
	Input : 

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}
	
	Output :

		1 (Yes, path exist from src to dst)
	
		Paths : 
			       {"1100", {"1000", {"1000",
		            "0100",	 "1100",  "1000",
		            "0110",  "0110",  "1110",
		            "0011"}  "0011"}  "0011"}

*/

#include<iostream>

using namespace std;

bool doesPathExist(char maze[][5], int m, int n, int i, int j) {
	// base case
	if(i == m || j == n) {
		// you've gone outside the grid
		return false;
	}

	if(i == m-1 && j == n-1) {
		// you're already at the destination
		return true;
	}

	// recursive case

	if(maze[i][j] == 'X') {
		return false;
	}

	bool fromRight = doesPathExist(maze, m, n, i+1, j);
	bool fromDown  = doesPathExist(maze, m, n, i, j+1);

	return fromRight || fromDown;

}

int main() {

	char maze[][5] = {"0000",
	                  "00X0",
	                  "000X",
	                  "0XX0"};

	int m = 4;
	int n = 4;

	doesPathExist(maze, m, n, 0, 0) ? cout << "Yes" << endl : cout << "No" << endl;



	return 0;
}


