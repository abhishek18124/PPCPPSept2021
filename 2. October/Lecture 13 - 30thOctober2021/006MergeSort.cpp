#include<iostream>

using namespace std;

void merge(int* A, int s, int m, int e) {
	// merges two sorted arrays A[s...m] and A[m+1..e]
	int i = s;
	int j = m+1;
	int k = s;

	int B[100];

	while(i <= m and j <= e) {
		if(A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}

	while(i <= m) {
		B[k] = A[i];
		i++;
		k++;
	}


	while(j <= e) {
		B[k] = A[j];
		j++;
		k++;
	}

	for(int k=s; k<=e; k++) {
		A[k] = B[k];
	}
}

void mergeSort(int* A, int s, int e) {
	// base case
	if(s >= e) {
		return;
	}

	// recursive case
	int m = s + (e-s)/2;
	mergeSort(A, s, m);
	mergeSort(A, m+1, e);
	merge(A, s, m, e);
}

int main() {

	int A[] = {7, 6, 5, 4, 3, 2, 1};
	int n = sizeof(A) / sizeof(int);

	mergeSort(A, 0, n-1);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}