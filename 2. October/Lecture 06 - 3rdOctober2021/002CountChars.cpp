#include<iostream>

using namespace std;

int main() {

	char ch;

	int digits = 0;
	int whitespaces = 0;
	int lowercase = 0;
	int uppercase = 0;
	int special = 0;

	while(true) {
		ch = cin.get();
		if(ch == '$') {
			break;
		}

		if(ch >= '0' && ch <= '9') {
			digits++;
		} else if(ch >= 'a' && ch <= 'z') {
			lowercase++;
		} else if(ch >= 'A' && ch <= 'Z') {
			uppercase++;
		} else if(ch == ' ' || ch == '\n' || ch == '\t') {
			whitespaces++;
		} else {
			special++;
		}

	}

	cout << "Number of digits = " << digits << endl;
	cout << "Number of lowercase letters = " << lowercase << endl;
	cout << "Number of uppercase letters = " << uppercase << endl;
	cout << "Number of whitespaces = " << whitespaces << endl;
	cout << "Number of special symbols = " << special << endl;

	return 0;
}