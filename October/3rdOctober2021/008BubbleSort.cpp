#include<iostream>

using namespace std;

int main() {

	int A[] = {5, 4, 3, 2, 1};

	int n = sizeof(A) / sizeof(int);

	int comps = 0;

	for(int i=1; i<n; i++) {
		// in the ith pass, place the largest element in the unsorted 
		// part of the array to its correct position.
		int swaps = 0;
		for(int j=0; j<n-i; j++) {
			if(A[j] > A[j+1]) {
				swap(A[j], A[j+1]);
				swaps++;
			}
			comps++;
		}
		if(swaps == 0) {
			break;
		}
	}

	cout << "Total number of comparision performed = " << comps << endl;
 
	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}