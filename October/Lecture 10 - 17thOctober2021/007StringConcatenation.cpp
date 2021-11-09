#include<iostream>
#include<cstring>

using namespace std;

void stringConcat(char* str1, char* str2) {
	int i = strlen(str1);
	int j = 0;

	while(j <= strlen(str2)) {
		str1[i] = str2[j];
		i++;
		j++;
	}

	// str1[i] = '\0'; // not required since j runs from 0 to strlen(str2)
}

int main() {

	char str1[100] = "hello";
	char str2[100] = "world";

	// strcat(str1, str2);

	// cout << str1 << endl;
	// cout << str2 << endl;

	stringConcat(str1, str2);

	cout << str1 << endl;
	cout << str2 << endl;


	return 0;
}