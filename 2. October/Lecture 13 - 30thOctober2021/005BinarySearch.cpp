#include<iostream>

using namespace std;

int f(int* A, int s, int e, int t) {
	// base case
	if(s > e) {
		// [s, e] corr. to an empty search space
		return -1;
	}

	// recursive case
	int m = s + (e-s)/2;
	if(A[m] == t) {
		return m;
	} else if(A[m] > t) {
		// reduce the search space from [s, e] to [s, m-1]
		return f(A, s, m-1, t);
	} else {
		// reduce the search space from [s, e] to [m+1, e]
		return f(A, m+1, e, t);
	}

}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);
	int t = 5;

	cout << f(A, 0, n-1, t) << endl;

	return 0;
}