#include<iostream>

using namespace std;

int main() {

	char A[] = {'x', 'y', 'z', '\0'};
	// char B[4] = {'a', 'b', 'c', 'd', '\0'};

	cout << A << endl;

	for(int i=0; A[i] != '\0'; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	char C[] = "abcde"; // \0 is added automatically when you initialise a 
						// char array using string literal

	cout << C << endl;

	// char D[5] = "vwxyz"; 

	return 0;
}