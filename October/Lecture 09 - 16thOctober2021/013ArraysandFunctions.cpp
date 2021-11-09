#include<iostream>

using namespace std;

int sumOfArray(int* B, int n) {
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += *(B+i);
	}
	return sum;
}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);
	int* ptr = A;
	int B[] = {1, 2, 3, 4, 5};
	int m = sizeof(B) / sizeof(int);
	ptr = B;
	// A = B; // name of an array cannot be assigned values

	cout << sumOfArray(ptr, m) << endl;
	cout << sumOfArray(&A[0], n) << endl;

	return 0;
}