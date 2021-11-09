#include<iostream>

using namespace std;

int arraySum(int* A, int n, int i) {

	// // base case
	// if(i == n) {
	// 	// array is empty
	// 	return 0;
	// }

	if(i == n-1) {
		return A[i];
	}

	return A[i] + arraySum(A, n, i+1);
}

int arraySum2(int* A, int n, int i) {

	// base case
	// if(i == -1) {
	// 	// array is empty
	// 	return 0;
	// }

	if(i == 0) {
		return A[i];
	}

	return A[i] + arraySum2(A, n, i-1);
}


int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	cout << arraySum(A, n, 0) << endl;
	cout << arraySum2(A, n, n-1) << endl;
}