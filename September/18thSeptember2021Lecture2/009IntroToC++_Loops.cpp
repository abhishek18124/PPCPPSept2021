#include<iostream>

using namespace std;

int main() {

	int n;

	cout << "Enter a positive number = ";

	cin >> n;

	int i = 100;

	while(i <= n) {

		cout << i << " ";
		i = i + 1;
	}

	cout << endl;

	i = 100;

	do {
		cout << i << " ";
		i = i + 1;
	} while(i <= n);

	return 0;
}