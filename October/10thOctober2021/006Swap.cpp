#include<iostream>

using namespace std;

void swapByValue(int x, int y) {
	swap(x, y);
}

void swapByReference(int& x, int& y) {
	swap(x, y);
}

int main() {

	int a = 10;
	int b = 20;

	swapByValue(a, b);

	cout << a << " " << b << endl;

	swapByReference(a, b);

	cout << a << " " << b << endl;


	return 0;
}