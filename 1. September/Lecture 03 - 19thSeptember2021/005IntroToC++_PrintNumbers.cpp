/*

1
2 3
4 5 6
7 8 9 10

*/


#include<iostream>

using namespace std;

int main() {

	int rows;

	cout << "Enter number of rows = ";
	cin >> rows;

	int i = 1;
	int no = 1;
	int j;

	while(i <= rows) {

		// in the ith rows, print i *
		j = 1;	
		
		while(j <= i) {
			cout << no << " ";
			j = j+1;
			no = no+1;
		}
		cout << endl;

		i = i+1;
	}

	return 0;
}