/*

Write a program to check count number of set bits in the given number.

Example :

Input : x = 6
Output: 2

Input : x = 7
Output: 3

*/

#include<iostream>
#include<bitset>
#include<cmath>

using namespace std;

int main() {

    int x = 97;

	int count = 0;

	for(int k=0; k < 32; k++) {

		if((1<<k)&x > 0) {
			count++;
		}

		// if((x>>k)&1 == 1) {
		// 	count++;
		// }
	}

	cout << "Number of set bits in " << x <<  " = " << count << endl;
	cout << bitset<32>(97) << endl;

	return 0;
}