#include<iostream>

using namespace std;

int main() {

	const float pi = 3.14;

	int r = 10;
	cout << 2 * pi * r << endl;

	// pi++; // const variable is read only

	// const int x; // it is imp. to assign value to a const  variable during declaration

	return 0;
}