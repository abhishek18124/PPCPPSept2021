#include<iostream>

using namespace std;

int main() {

	int ans = 0;

	int n;

	cout << "Enter n = ";

	cin >> n;

	int i = 1; 

	int no;

	while(i <= 2*n + 1) {
		// cout << "Enter a number = ";
		cin >> no;
		ans = ans ^ no;
		i++;
	}

	cout << ans;

	return 0;
}