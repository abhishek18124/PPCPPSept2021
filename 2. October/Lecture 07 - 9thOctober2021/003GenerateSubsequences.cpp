#include<iostream>

using namespace std;

int main( ) {	

	int A[] = {1, 2, 3};
	int n = sizeof(A) / sizeof(int);

	// iterate over 2^n nos. in the range [0, 2^n-1]
	for(int no=0; no < (1<<n); no++) { // 1<<n = 2^n
		// for each no, iterate over its n-bit binary representation from right to left
		for(int i=0; i<n; i++) {
			// if the ith bit is set, include the element at the ith index in the subseq.
			if((1<<i)&no) { // or (no>>i)&1
				cout << A[i] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}