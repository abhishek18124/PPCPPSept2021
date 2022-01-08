#include<iostream>

using namespace std;

int main() {

	int A[10];

	int n = sizeof(A) / sizeof(A[0]);

	// A[0], A[1], A[2], .. , A[n-1]

	for(int i=0; i<n; i++) {
		cin >> A[i];
	}


	// printing array from left to right
	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	// printing array in reverse from right to left
	for(int i=n-1; i>=0; i--) {
		cout << A[i] << " ";
	}

	cout << endl;

	// assignment

	A[2] = 500;

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	cout << A[20] << endl;
	
	return 0;
}