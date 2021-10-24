#include<iostream>

using namespace std;

int searchFirstOccurence(int* A, int n, int t, int i) {
	// base case
	if(i == n) {
		// A is empty
		return -1;
	}

	if(A[i] == t) {
		return i;
	}

	return searchFirstOccurence(A, n, t, i+1);
}

void searchAllOccurrences(int* A, int n, int t, int i) {
	// base case
	if(i == n) {
		// A is empty
		return;
	}

	if(A[i] == t) {
		cout << i << " ";
	}

	searchAllOccurrences(A, n, t, i+1);
}

int searchLastOccurence(int* A, int n, int t, int i) {
	// base case
	if(i == -1) {
		// A is empty
		return -1;
	}

	if(A[i] == t) {
		return i;
	}

	return searchLastOccurence(A, n, t, i-1);
}

int main() {

	int A[] = {1, 4, 2, 3, 4, 4, 5};
	int n = sizeof(A) / sizeof(int);
	int t = 4;

	cout << searchFirstOccurence(A, n, t, 0) << endl;
	searchAllOccurrences(A, n, t, 0); cout << endl;
	cout << searchLastOccurence(A, n, t, n-1) << endl;

	return 0;
}