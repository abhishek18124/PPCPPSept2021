/*

Write a program that will continuously ask the user for an integer and stops asking
as soon as user enters -1.

*/

#include<iostream>

using namespace std;

int main() {

	int n;

	while(true) {

		cout << "Enter the value of n > ";

		cin >> n;

		if(n == -1) {
			break;
		}
		
		cout << "You've entered " << n << endl;
	}

	cout << "You've terminated the loop!" << endl;
	return 0;
}