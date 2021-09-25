/*
Write a program to calculate sum of digits of a given number.
*/

#include<iostream>

using namespace std;

int main() {

	int n;

	cout << "Enter a non-negative integer : ";
	cin >> n;

	int sum = 0;

	while(n > 0) {
		int digit = n % 10; 
		sum = sum + digit;
		n = n / 10;
	}	

	cout << "Sum of digits = " << sum << endl;

	return 0;
}
