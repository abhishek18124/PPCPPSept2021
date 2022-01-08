#include<iostream>
#include<cstring>

using namespace std;

int f(char* str, int i) {
	// base case
	if(i == 0) {
		return (str[0]-'0');
	}

	// recursive
	return f(str, i-1)*10 + (str[i]-'0');
}

int main() {

	char str[] = "4992";
	int n = strlen(str);

	int x = f(str, n-1);
	cout << x << endl;

	return 0;
}