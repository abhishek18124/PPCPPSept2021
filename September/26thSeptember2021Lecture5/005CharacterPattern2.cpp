/*

Write a program to print the following pattern

A B C D E E D C B A
A B C D D C B A
A B C C B A
A B B A
A A

here, n i.e. number of rows is equal to five.

*/

#include<iostream>

using namespace std;

int main() {

	int n = 5;

	for(int i=1; i<=n; i++) {
		// in the ith row, print n-i+1 characters in the inc. order starting with 'A'
		char ch = 'A';
		for(int j=1; j<=n-i+1; j++) {
			cout << ch;
			ch++;
		}

		ch--;

		// in the ith row, print n-i+1 characters in the dec order starting with 
		for(int j=1; j<=n-i+1; j++) {
			cout << ch;
			ch--;
		}
		cout << endl;
	}

	return 0;
}