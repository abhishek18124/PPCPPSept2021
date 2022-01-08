#include<iostream>

using namespace std;

void isEven(int n) {
	if(n%2 == 0) {
		cout << n << " is an even number" << endl;
	} else {
		cout << n << " is an odd number" << endl;
	}
}

int main() {

	isEven(5);

	return 0;
}