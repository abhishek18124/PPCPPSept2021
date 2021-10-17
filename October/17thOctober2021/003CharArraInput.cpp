#include<iostream>

using namespace std;

void readString(char* str, char delimiter='\n') {
	char ch;
	int i = 0;
	while(true) {
		ch = cin.get();
		if(ch == delimiter) {
			break;
		}
		str[i] = ch;
		i++;
	}

	str[i] = '\0'; // add null character explicitly
}

int main() {

	char str[100];

	// cin >> str; // '\0' is added automatically, cin>> terminates as soon as it encounters whitespace

	readString(str);

	// cin.getline(str, 10, '$');

	cout << str << endl;


	return 0;
}