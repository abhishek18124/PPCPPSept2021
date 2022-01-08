#include<iostream>

using namespace std;

int main() {

	int A[3][4];

	// cout << (A[0] == &A[0][0]) << endl;
	// cout << (A[1] == &A[1][0]) << endl;
	// cout << (A[2] == &A[2][0]) << endl;  

	cout << A[0] << " " << A << endl;
	cout << A[1] << " " << A+1 << endl;
	cout << A[2] << " " << A+2 << endl;
 	
	return 0;
}