/*

Given a n x n chess board, count the number of ways a chess elephant can move from (0, 0)
to (n-1, n-1) such that it can only move in the right or down direction at a time.

Example 
	Input : n = 2
	Output: 2
	
	Input : n = 3
	Output: 14
	
	Input : n = 4
	Output: 106

*/

#include<iostream>

using namespace std;

int countWays(int n, int i, int j) {
	// base case
	if(i == n-1 and j == n-1) {
		// you've reached the destination
		return 1;
	}

	// additional base to handle situation when i>=n || j>=n

	if(i >= n || j >= n) {
	    // you've gone beyond the boundaries of the chessboard
		return 0;
	}

	// recursive

	// you're at the (i, j)th cell, and you've to decide should you move right or
	// you should move down


	// move right

	int count1 = 0;
	for(int k=1; k<n; k++) {
		// if(j+k < n) {
		// 	count1 += countWays(n, i, j+k);
		// }
	    count1 += countWays(n, i, j+k);
	}

	// move down

	int count2 = 0;
	for(int k=1; k<n; k++) {
		// if(i+k < n) {
		// 	count2 += countWays(n, i+k, j);
		// }
		count2 += countWays(n, i+k, j);
	}

	return count1 + count2;

}

int main() {

	int n = 4;

	cout << countWays(n, 0, 0) << endl;

	return 0;
}