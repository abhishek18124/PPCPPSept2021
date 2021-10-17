#include<iostream>

using namespace std;

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	for(int i=0; i<n; i++) {
		cout << A[i] << " " << *(A+i) << endl;
	}

	cout << endl;

	for(int i=0; i<n; i++) {
		cout << &A[i] << " " << (A+i) << endl;
	}

	return 0;
}