/*

N Queens Problem

The problem is to place 'n' queens on an 'n x n' chessboard, so that no two queens are attacking 
each other, this means that no two queens are in the same row, the same column, or the same diagonal.

Example 
	Input : N = 4
	Output: 
			_ Q _ _	     _ _ Q _
	        _ _ _ Q      Q _ _ _ 
	        Q _ _ _      _ _ _ Q
	        _ _ Q _      _ Q _ _ 

Constraint:
	1<=n<=10	        

*/

#include<iostream>

using namespace std;

void placeNQueens(int n, int* QPos, int r) {

	// base case

	if(r == n) {

		for(int i=0; i<n; i++) {
			cout << QPos[i] << " ";
		}

		cout << endl;
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(QPos[i] == j) {
					cout << "Q ";
				} else  {
					cout << "- ";
				}
			}
			cout << endl;
		}
		cout << endl;

		

		cout << endl;
		return;
	}

	// place the Qr

	for(int j=0; j<n; j++) {
		bool canPlace = true;

		for(int i=0; i<r; i++) {
			if(QPos[i] == j || QPos[i] == j+(r-i) || QPos[i] == j-(r-i)) {
				canPlace = false;
				break;
			}
		}

		if(canPlace) {
			QPos[r] = j;
			placeNQueens(n, QPos, r+1);
		}
	}
}

int main() {

	int n = 4;
	int QPos[4];

	placeNQueens(n, QPos, 0);

	return 0;
}