#include<iostream>

using namespace std;

void readInput(int** ptr, int m, int n) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> ptr[i][j];
		}
	}
}

void printOutput(int** ptr, int m, int n) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {

	int m = 3;
	int n = 4;

	int **ptr = new int*[m];
	for(int i=0; i<m; i++) {
		ptr[i] = new int[n];
	}

	readInput(ptr, m, n);

	printOutput(ptr, m, n);

	return 0;
}