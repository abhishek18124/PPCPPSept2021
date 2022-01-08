#include<iostream>

using namespace std;

int binarySearch(int A[], int n, int t) {

	int s = 0;
	int e = n-1;

	while(s <= e) {
		int m = s + (e-s)/2;
		if(A[m] == t) {
			// terminate the algorithm and return m
			return m;
		} else if(A[m] > t) {
			// reduce your search space from [s, e] to [s, m-1]
			e = m-1;
		} else {
			// reduce your search space from [s, e] to [m+1, e]
			s = m+1;
		}
	}

	return -1;
}

int main() {

	int A[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(A) / sizeof(int);

	int t = 10;

	cout << binarySearch(A, n, t) << endl;

	return 0;
}