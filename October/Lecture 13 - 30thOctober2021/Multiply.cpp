#include<iostream>

using namespace std;

int f(int a, int b) {
	// base case
	if(b == 0) {
		// you want to a 0 times
		return 0;
	}

	// recursive case
	return a + f(a, b-1);
}

int main() {

	int a = 3;
	int b = 4;

	cout << f(a, b) << endl;

	return 0;
}