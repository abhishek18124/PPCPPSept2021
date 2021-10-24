#include<iostream>

using namespace std;

void printIncreasing(int n) {
	// base case
	if(n == 0) {
		return;
	}

	// recursive case
	printIncreasing(n-1);
	cout << n << " ";
}

void printDecreasing(int n) {
	// base case
	if(n == 0) {
		return;
	}

	// recursive case
	cout << n << " ";
	printDecreasing(n-1);
}

int main() {

	int n = 10;

	printIncreasing(n); cout << endl;
	printDecreasing(n); cout << endl;

	return 0;
}