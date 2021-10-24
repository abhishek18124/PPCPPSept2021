#include<iostream>

using namespace std;

int main() {

	int A[10][10];

	int m;
	cin >> m; // must be <= 10

	int n;
	cin >> n; // must be <= 10

	// for(int i=0; i<m; i++) {
	// 	// read values for the ith row
	// 	for(int j=0; j<n; j++) {
	// 		cin >> A[i][j];
	// 	}
	// }

	// for(int i=0; i<m; i++) {
	// 	for(int j=0; j<n; j++) {
	// 		cout << A[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;

	for(int j=0; j<n; j++) {
		for(int i=0; i<m; i++) {
			cin >> A[i][j];
		}
	}

	// for(int j=0; j<n; j++) {
	// 	for(int i=0; i<m; i++) {
	// 		cout << A[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	

	return 0;
}