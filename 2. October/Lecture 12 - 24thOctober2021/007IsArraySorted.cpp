#include<iostream>

using namespace std;

bool isSorted(int* A, int n, int i) {
	// base case
	if(i == n-1) {
		// you're left with only the last element
		return true;
	}

	return A[i] < A[i+1] && isSorted(A, n, i+1);
}

int main() {

	int A[] = {1, 2, 5, 4, 5};
	int n = sizeof(A) / sizeof(int);

	isSorted(A, n, 0) ? cout << "Sorted" << endl : cout << "Not Sorted" << endl;

	return 0;
}