#include<iostream>

using namespace std;

int main() {

	int A[] = {5, 4, 1, 3, 2};
	int n = sizeof(A) / sizeof(int);

	for(int i=1; i<n; i++) {
		// in the ith phase, we insert the element at the ith idx i.e. key to 
		// its correct position in the sorted part of the array.
		int key = A[i];
		int j = i-1;
		while(j >= 0 && A[j] > key) {
			// shift the jth element to the next position
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}