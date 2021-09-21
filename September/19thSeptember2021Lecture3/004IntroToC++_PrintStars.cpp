/*

*
**
***
****

*/


#include<iostream>

using namespace std;

int main() {

	int rows;

	cout << "Enter number of rows = ";
	cin >> rows;

	int i = 1;

	while(i <= rows) {

		// in the ith rows, print i *
		int j = 1;
		while(j <= i) {
			cout << "* ";
			j = j+1;
		}
		cout << endl;
		i = i+1;
	}

	return 0;
}