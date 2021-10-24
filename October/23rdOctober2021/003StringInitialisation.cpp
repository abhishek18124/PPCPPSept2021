#include<iostream>

using namespace std;

int main() {

	// initialisation of string object

	// string str = "Hello";
	string str("Hello");

	string str1 = "Abhishek";
	// string str2 = str1;
	string str2(str1);

	cout << str2 << endl;

	char ch[] = "World";
	string str4(ch); // str4 = ch;

	cout << str4 << endl;

	return 0;
}