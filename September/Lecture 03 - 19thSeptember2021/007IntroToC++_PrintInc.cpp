#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter the number of rows = ";
	cin >> n;

	int i = 1;

	while(i <= n) {

		// print the ith row

		// print (n-i) spaces

		int j = 1;

		while(j <= (n-i)) {
			cout << " ";
			j = j + 1;
		}

		// print i nos. in the inc. order starting with i

		j = 1;
		int no = i;

		while(j <= i) {
			cout << no;
			no = no + 1;
			j = j + 1;
		}

		// print i-1 nos. in the dec. order starting with 2i-2

		j = 1;
		no = 2*i - 2;

		while(j <= i-1) {
			cout << no;
			j = j + 1;
			no = no - 1;
		}

		cout << endl;

		i = i + 1;
	}

	return 0;
}