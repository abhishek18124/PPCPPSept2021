/*
	
	You are given an m x n binary matrix grid. An island is a group of 1's 
	(representing land) connected 4-directionally (horizontal or vertical.) 
	You may assume all four edges of the grid are surrounded by water.

	The area of an island is the number of cells with a value 1 in the island.
	Return the maximum area of an island in grid. If there is no island, return 0.

*/

#include<iostream>
#include<vector>

using namespace std;

int dfsHelper(vector<vector<int>> grid, vector<vector<bool>>& visited, int m,  int n, int i, int j) {
	// mark the (i, j)th vertex as visited
	visited[i][j] = true;

	int count = 1; // to store no. of vertices in the given component of which 
		           // the (i, j)th vertex is the source

	int n_x = i;
	int n_y = j+1;

	if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n &&
	   grid[n_x][n_y] == 1 && 
	   !visited[n_x][n_y]) {
		count += dfsHelper(grid, visited, m, n, n_x, n_y);
	}

	// n_x = i;
	// n_y = j-1;

	// if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n &&
	//    grid[n_x][n_y] == 1 && 
	//    !visited[n_x][n_y]) {
	// 	count += dfsHelper(grid, visited, m, n, n_x, n_y);
	// }

	// n_x = i+1;
	// n_y = j;

	// if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n &&
	//    grid[n_x][n_y] == 1 && 
	//    !visited[n_x][n_y]) {
	// 	count += dfsHelper(grid, visited, m, n, n_x, n_y);
	// }

	// n_x = i-1;
	// n_y = j;

	// if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n &&
	//    grid[n_x][n_y] == 1 && 
	//    !visited[n_x][n_y]) {
	// 	count += dfsHelper(grid, visited, m, n, n_x, n_y);
	// }

	int delta_x[4] = {0, 0, 1, -1};
	int delta_y[4] = {1, -1, 0, 0};

	for(int k=0; k<4; k++) {
		int n_x = i+delta_x[k];
		int n_y = j+delta_y[k];
		if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n &&
	   	   grid[n_x][n_y] == 1 && 
	       !visited[n_x][n_y]) {
			count += dfsHelper(grid, visited, m, n, n_x, n_y);
		}
	}

	return count;

}

int largestIsland(vector<vector<int>> grid, int m, int n) {
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	int maxArea = 0;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(grid[i][j] == 1 and !visited[i][j]) {
				maxArea = max(maxArea, dfsHelper(grid, visited, m, n, i, j));
			}
		}
	}
	return maxArea;
}

int main() {

	vector<vector<int>> grid = {{1, 0, 0, 1, 0},
                                {1, 0, 1, 0, 0},
                                {0, 0, 1, 0, 1},
                                {1, 0, 1, 1, 1},
                                {1, 0, 1, 1, 0}};

	// vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
	//                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
	//                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
	//                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
	//                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
	//                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
	//                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
	//                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    int m = grid.size();
    int n = grid[0].size();

    cout << largestIsland(grid, m, n) << endl;

    return 0;
}