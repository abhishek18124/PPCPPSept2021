/*

Write a program to print numbers from 1 to 10.

*/

#include<iostream>

using namespace std;

int main() {

	for(int i=1; i<=10; i++) {
		if(i == 2) continue;
		cout << i << " ";
	}

	cout << endl;

	return 0;
}
