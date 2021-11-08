/*

Suppose there is a ladder with n steps. A person standing at the bottom of the ladder and wants to 
reach to its top. Assume the person can take atmost k steps at a time. Then, count the number 
of ways, the person can reach the top of the ladder.

Example 
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1], 
	              [1, 1, 2], 
	              [1, 2, 1], 
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>

using namespace std;

int countNumberOfWays(int n, int k, int i) {
	// base case
	if(i == n) {
		return 1;
	}

	// if(i > n) {
	// 	return 0;
	// }

	// recursive case
	int count = 0;
	for(int j=1; j<=k; j++) {
		if(i+j <= n) {
			count += countNumberOfWays(n, k, i+j);
		}
		// count += countNumberOfWays(n, k, i+j);
	}

	return count;
}


int main() {

	int n = 4;
	int k = 3;

	cout << countNumberOfWays(n, k, 0) << endl;

	return 0;
}