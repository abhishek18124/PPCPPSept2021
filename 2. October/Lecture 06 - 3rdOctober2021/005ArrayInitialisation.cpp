#include<iostream>

using namespace std;

int B[5];

int main() {

	int A[5] = {10};

	int n = sizeof(A)/sizeof(A[0]);
	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	for(int i=0; i<5; i++) {
		cout << B[i] << " ";
	}

	cout << endl;

	char C[5] = {};
	for(int i=0; i<5; i++) {
		cout << int(C[i]) << " ";
	}

	cout << endl;


	int D[] = {2, 3, 9, 8, 0};

	for(int i=0; i<5; i++) {
		cout << D[i] << " ";
	}

	cout << endl;

	return 0;
}