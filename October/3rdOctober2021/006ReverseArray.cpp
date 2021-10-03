#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int A[5] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(A[0]);

	int i = 0;
	int j = n-1;

	while(i < j) {
		
		// int temp = A[i];
		// A[i] = A[j];
		// A[j] = temp;

		swap(A[i], A[j]);
		i++;
		j--;

	}

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	reverse(A, A+n);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;


	return 0;
}