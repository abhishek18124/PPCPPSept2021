/*

Given an integer matrix 'mat' of dimensions m x n, write a program that prints
the matrix in wave form.

Example :
	Input : mat[][] = [[1, 2, 3],
					   [4, 5, 6],
					   [7, 8, 9]]

	Output : 1 4 7 8 5 2 3 6 9

*/

#include<iostream>

using namespace std;

int main() {

	int mat[][3] = {{1, 2, 3},
					{4, 5, 6},
					{7, 8, 9}};

	for(int j=0; j<3; j++) {
		if(j%2 == 0) {
			// j represents an even column, go from top-bottom
			for(int i=0; i<3; i++) {
				cout << mat[i][j] << " ";
			}
		} else {
			// j representes an odd column, go from bottom-top
			for(int i=2; i>=0; i--) {
				cout << mat[i][j] << " ";
			}
		}
	}

	cout << endl;
	
	return 0;
}