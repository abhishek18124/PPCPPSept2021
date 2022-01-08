#include<iostream>

using namespace std;

int main() {

	int x;

	cout << "Enter a value for x = ";

	cin >> x;

	if(x > 10) {
		cout << "Yes " << x << " is greater than 10" << endl;
	} else {
		cout << "No "  << x << " is not greater than 10" << endl;
	}

	return 0;
}