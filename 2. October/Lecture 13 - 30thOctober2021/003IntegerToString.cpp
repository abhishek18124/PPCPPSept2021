#include<iostream>

using namespace std;

string map[] = {"zero", "one", "two", "three", "four", "five",
				"six", "seven", "eight", "nine"};

void f(int n) {

	// base case
	if(n == 0) {
		return;
	}

	// recursive case
	f(n/10);
	int digit = n%10;
	cout << map[digit] << " ";
}



int main() {

	int n = 456;

	f(n);

	return 0;
}