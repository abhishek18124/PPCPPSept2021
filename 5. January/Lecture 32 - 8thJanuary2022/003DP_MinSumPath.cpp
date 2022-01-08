/*

Given a m x n grid filled with non-negative numbers, find a path from (0, 0) to (m-1, n-1), 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example : 
	Input: grid = [[1,3,1],
	               [1,5,1],
	               [4,2,1]]

	Output: 7
	Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Constraints :
	1 <= m, n <= 200
	0 <= grid[i][j] <= 100

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minSum(vector<vector<int>>& grid, int i, int j) {
	// base case
	if(i == 0 && j == 0) {
		return grid[0][0];
	}

	// recursive case
	if(i == 0) {
		return grid[0][j] + minSum(grid, i, j-1);
	}

	if(j == 0) {
		return grid[i][0] + minSum(grid, i-1, j);
	}

	int X = minSum(grid, i-1, j);
	int Y = minSum(grid, i, j-1);

	return grid[i][j] + min(X, Y);
}

int minSumTopDown(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
	// base case
	if(i == 0 && j == 0) {
		return dp[0][0]=grid[0][0];
	}

	// lookup
	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	// recursive case
	if(i == 0) {
		return dp[0][j] = grid[0][j] + minSumTopDown(grid, i, j-1, dp);
	}

	if(j == 0) {
		return dp[i][0] = grid[i][0] + minSumTopDown(grid, i-1, j, dp);
	}

	int X = minSumTopDown(grid, i-1, j, dp);
	int Y = minSumTopDown(grid, i, j-1, dp);

	return dp[i][j] = grid[i][j] + min(X, Y);
}

int minSumBottomUp(vector<vector<int>>& grid, int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n));
	
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(i == 0 && j == 0) {
				dp[0][0] = grid[0][0];
			} else if(i == 0) {
				dp[0][j] = grid[0][j] + dp[0][j-1];
			} else if(j == 0) {
				dp[i][0] = grid[i][0] + dp[i-1][0];
			} else {
				int X = dp[i-1][j];
				int Y = dp[i][j-1];
				dp[i][j] = grid[i][j] + min(X, Y);
 			}
		}
	}

	return dp[m-1][n-1];
}

int main() {

	vector<vector<int>> grid = {{1, 3, 1},
   								{1, 5, 1},
   								{4, 2, 1}};

   	int m = grid.size();
   	int n = grid[0].size();

   	cout << minSum(grid, m-1, n-1) << endl;

   	vector<vector<int>> dp(m, vector<int>(n, -1));
   	cout << minSumTopDown(grid, m-1, n-1, dp) << endl;
   	cout << minSumBottomUp(grid, m, n) << endl;


	return 0;
}






