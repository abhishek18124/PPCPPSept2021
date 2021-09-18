#include<iostream>

using namespace std;

int main() {

	int a, b, c;

	cout << "Enter value of a = ";
	cin >> a;

	cout << "Enter value of b = ";
	cin >> b;
	
	cout << "Enter value of c = ";
	cin >> c;

	if(a > b && a > c) {
		cout << a << " is the largest." << endl;
	} else if(b > c) {
		cout << b << " is the largest." << endl;
	} else {
		cout << c << " is the largest." << endl;
	}
	
	return 0;
}