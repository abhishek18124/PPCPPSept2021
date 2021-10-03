#include<iostream>

using namespace std;

int main() {
	
	int A[10];

	int n = sizeof(A) / sizeof(int);

	for(int i=0; i<n; i++) {
		cin >> A[i];
	}

	int target;

	cout << "Enter target = ";
	cin >> target;

	int i;

	for(i=0; i<n; i++) {
		if(A[i] == target) {
			cout << target << " is found at index " << i << endl;
			break;
		}
	}

	if(i == n) {
		cout << target << " was not found" << endl;
 	}

	return 0;
}