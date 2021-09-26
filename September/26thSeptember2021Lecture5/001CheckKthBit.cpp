/*

Write a program to check if the kth bit of a given number x is set (1).

Example :

Input : x = 6, k = 1
Output: true

Input : x = 7, k = 3
Output: false

*/

#include<iostream>

using namespace std;

int main() {

	int x = 42;
	int k = 2;

	// 1. using >>

	(x>>k)&1 ? cout << "true" << endl : cout << "false" << endl;

	// if((x>>k)&1) {
	// 	cout << "true" << endl;
	// } else {
	// 	cout << "false" << endl;
	// }

	// 2. using <<

	(1<<k)&x ? cout << "true" << endl : cout << "false" << endl;

	// if((1<<k)&x) {
	// 	cout << "true" << endl;
	// } else {
	// 	cout << "false" << endl;
	// }

	return 0;
}









