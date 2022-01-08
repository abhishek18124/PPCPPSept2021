/*

There are two sorted arrays. First one is of size m+n containing only m elements. 
Another one is of size n and contains n elements. Merge these two arrays such that 
the output is sorted without using extra space.

Example :
	
	Input : A[] = [1, 3, 5, 6, - , - , -] B[] = [2, 4, 7]
	Output: [1, 2, 3, 4, 5, 6, 7]

*/

#include<iostream>

using namespace std;

// Approach - (m+n) steps

void merge(int A[], int n1, int B[], int n2) {
	int m = n1 - n2;
	int n = n2;

	int i = m-1;
	int j = n-1;
	int k = m+n-1;

	while(i >= 0 && j >= 0) {
		if(A[i] > B[j]) {
			A[k] = A[i];
			i--;
		} else {
			A[k] = B[j];
			j--;
		}
		k--;
	}

	while(j >= 0) {
		A[k] = B[j];
		k--;
		j--;
	}
}

int main() {

	int A[6] = {2, 4, 6};
	int B[3] = {1, 3, 5};

	int n1 = sizeof(A) / sizeof(int); // n1 = m+n
	int n2 = sizeof(B) / sizeof(int); // n2 = n

	merge(A, n1, B, n2);

	for(int i=0; i<n1; i++) {
		cout << A[i] << " ";
	}

	return 0;
}