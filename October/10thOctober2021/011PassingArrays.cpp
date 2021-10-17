#include<iostream>

using namespace std;

int sumOfArray(int B[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += B[i];
	}
	return sum;
}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	cout << sumOfArray(A, n) << endl;

	return 0;
}