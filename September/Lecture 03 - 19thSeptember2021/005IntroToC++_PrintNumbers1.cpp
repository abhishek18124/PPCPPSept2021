/*

1
1 2
1 2 3
1 2 3 4

*/


#include<iostream>

using namespace std;

int main() {

	int n = 4;

	// cout << "Enter number of rows = ";
	// cin >> n;

	int i = 1;
	int j;

	while(i <= n) {

		// in the ith rows, print i *
		j = 1;	
		
		while(j <= i) {
			cout << j << " ";
			j = j+1;
		}
		cout << endl;

		i = i+1;
	}

	return 0;
}