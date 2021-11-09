#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[100] = "hello world";

	int length = 0;

	for(int i=0; str[i] != '\0'; i++) {
		length++;
	}

	cout << "Length of \"" << str << "\" = " << length << endl;

	cout << "Length of \"" << str << "\" = " << strlen(str) << endl;

	return 0;
}