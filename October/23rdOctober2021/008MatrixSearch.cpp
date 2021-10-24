/*

Given an integer matrix 'mat' of dimensions m x n and an integer 't', write a program 
to search for 't' in 'mat'. 

If 't' is present in the matrix print its coordinates otherwise print (-1, -1).

Example :
	Input : mat[][] = [[1,  2,  3,  4],
					   [5,  6,  7,  8],
					   [9,  10, 11, 12],
					   [13, 14, 15, 16]]

			t = 10

	Output: (2, 1)

*/

#include<iostream>

using namespace std;

pair<int, int> matrixSearch(int mat[][4], int t) {
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(mat[i][j] == t) {
				return {i, j}; // make_pair(i, j);
			}
		}
	}

	return {-1, -1};
}

int main() {

	int mat[][4]  = {{1,  2,  3,  4},
					 {5,  6,  7,  8},
					 {9,  10, 11, 12},
					 {13, 14, 15, 16}};

	int t = 100;

	pair<int, int> p = matrixSearch(mat, t);

	cout << p.first << " " << p.second << endl;

	return 0;
}