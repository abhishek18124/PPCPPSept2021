#include<iostream>

using namespace std;

int main() {

	int n;
	
	cout << "Enter a positive number = ";
	cin >> n;

	int i = 1;
	while(i <= n) {
		cout << i << " ";
		i = i+1;
	}

	return 0;
}