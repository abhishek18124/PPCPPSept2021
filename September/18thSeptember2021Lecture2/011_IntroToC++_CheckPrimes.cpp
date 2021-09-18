#include<iostream>

using namespace std;

int main() {

	int n;
	
	cout << "Enter a positive number = ";
	cin >> n;

	int i = 2;

	while(i < n) {
		if(n%i == 0) {
			cout << n << " is not a prime number !" << endl;
			return 0;
		}

		i = i+1;
	}

	cout << n << " is a prime number!" << endl;

	return 0;
}