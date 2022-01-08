#include<iostream>

using namespace std;

int f(int n) {
	// base case
	if(n == 0) return 1;

	// recursive
	return n * f(n-1);
}


int main() {

	int n = 5;

	cout << f(n) << endl;

	return 0;
}