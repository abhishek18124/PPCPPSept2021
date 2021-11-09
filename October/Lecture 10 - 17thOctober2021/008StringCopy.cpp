#include<iostream>
#include<cstring>

using namespace std;

void stringCopy(char* dest, char* src) {
	int i = 0;
	int n = strlen(src);

	while(i <= n) {
		dest[i] = src[i];
		i++;
	}
}

int main() {

	char str1[100] = "hello";
	char str2[100] = "goodbye";

	cout << str1 << " " << str2 << endl;

	// stringCopy(str1, str2);

	strcpy(str1, str2);

	cout << str1 << " " << str2 << endl;


	return 0;
}