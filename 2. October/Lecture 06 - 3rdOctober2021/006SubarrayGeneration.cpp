#include<iostream>

using namespace std;

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	// iterate over all the possible starting indices
	for(int i=0; i<n; i++) {
		// iterate over all the possible ending indices
		for(int j=i; j<n; j++) {
			// now, iterate over the elements of the array that start at index i and
			// end at index j
			for(int k=i; k<=j; k++) {
				cout << A[k] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}