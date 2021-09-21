#include<iostream>

using namespace std;

int main() {

	char ch;

	cout << "Enter a character = ";

	cin >> ch;

	if(ch >= 'A' && ch <= 'Z') {
		cout << "uppercase" << endl;
	} else if(ch >= 'a' && ch <= 'z') {
		cout << "lowercase" << endl;
	} else {
		cout << "invalid character" << endl;
	}

	return 0;
}