/*

Given a number n, count the minimum steps to reduce n to 1 such that at each 
step you may

	reduce n to n/2 if n is divisible by 2
	or reduce n to n/3 if n is divisible by 3
	or reduce n to n-1 by decrementing n by 1

Example :
	Input : n = 10
	Output : 3

	Input : 6
	Output : 2

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minSteps(int n) {

	// base case
	if(n == 1) {
		return 0;
	}

	// recursive case
	int x = INT_MAX;
	if(n%3 == 0) {
		x = minSteps(n/3);
	}

	int y = INT_MAX;
	if(n%2 == 0) {
		y = minSteps(n/2);
	}

	int z = minSteps(n-1);

	return 1 + min(x, min(y, z));

}

int minStepsBottomUp(int n) {
	vector<int> dp(n+1); // 0th index is reserved

	dp[1] = 0; // fill the index corr. to the base case

	for(int i=2; i<=n; i++) {

		// at the ith idx of the dp[], we store the
		// result of f(i) i.e. min steps reqd. to 
		// reduce amt. i to 1

		int x = INT_MAX;
		if(i%3 == 0) {
			x = dp[i/3];
		}

		int y = INT_MAX;
		if(i%2 == 0) {
			y = dp[i/2];
		}

		int z = dp[i-1];

		dp[i] = 1 + min(x, min(y, z));
	}

	return dp[n]; // at the nth index we store the final ans.

}

int main() {

	int n = 6;

	cout << minSteps(n) << endl;
		
	return 0;
}