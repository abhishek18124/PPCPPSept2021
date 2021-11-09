/*

Write a program to print the following pattern

*
**
***
****
*****
****
***
**
*

here, n i.e. number of rows with increasing pattern is equal to five.

*/

#include<iostream>

using namespace std;

int main() {

	int n = 5;

	for(int i=1; i<=n; i++) {
		// in the ith row, print i stars

		for(int j=1; j<=i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	for(int i=n; i>1; i--) {
		// in the ith row, print i-1 stars
		for(int j=1; j<=i-1; j++) {
			cout << "*";
		}
		cout << endl;
	}


	return 0;
}