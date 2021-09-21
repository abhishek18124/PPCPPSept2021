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
	int no;

	while(i <= rows) {

		if(i%2 == 0) {
			no = 0;
		} else {
			no = 1;
		}

		// in the ith rows, print i *
		int j = 1;	
		
		while(j <= i) {
			cout << no << " ";
			j = j + 1;
			no = 1 - no;
		}

		cout << endl;

		i = i+1;
	}

	return 0;
}