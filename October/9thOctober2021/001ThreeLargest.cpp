#include<iostream>
#include<climits>

using namespace std;

int main() {

	int A[] = {5, 0, -1, -2, 3};
	int n = sizeof(A) / sizeof(int);

	int first  = INT_MIN;
	int second = INT_MIN;
	int third  = INT_MIN;

	for(int i=0; i<n; i++) {
		if(A[i] > first) {
			third = second;
			second = first;
			first = A[i];
		} else if(A[i] > second) {
			third = second;
			second = A[i];
		} else if(A[i] > third) {
			third = A[i];
		}
	}

	cout << first << " " << second << " " << third << endl;

	return 0;
}