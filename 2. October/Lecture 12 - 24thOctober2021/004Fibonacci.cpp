#include<iostream>

using namespace std;

int f(int n) {
	// base case
	if(n == 0 || n == 1) {
		return n;
	}

	// recursive case
	return f(n-1) + f(n-2);
}


int main() {

	int n = 7;

	cout << f(n) << endl;

	return 0;
}