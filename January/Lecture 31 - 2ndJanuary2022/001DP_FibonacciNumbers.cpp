/*

Given a number n, find the nth fibonacci no.

Example :
	Input : n = 7
	Output : 13

*/

#include<iostream>
#include<vector>

using namespace std;

int fibo(int n) {

	// base case
	if(n == 0 || n == 1) {
		return n;
	}

	// recursive case
	return fibo(n-1) + fibo(n-2);

}

int fiboTopDown(int n, vector<int>& dp) {

	// base case
	if(n == 0 || n == 1) {
		return dp[n] = n;
	}

	// lookup
	if(dp[n] != -1) {
		return dp[n];
	}


	// recursive case
	return dp[n] = fiboTopDown(n-1, dp) + fiboTopDown(n-2, dp);

}

int fiboBottomUp(int n) {
	vector<int> dp(n+1);

	dp[0] = 0;
	dp[1] = 1;

	for(int i=2; i<=n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}


int fiboBottomUpSpaceOptimised(int n) {

	int a = 0;
	int b = 1;

	for(int i=2; i<=n; i++) {
		int c = a + b;
		a = b;
		b = c;
	}

	return b;
}

int main() {

	int n = 7;

	cout << fibo(n) << endl;

	vector<int> dp(n+1, -1);
	cout << fiboTopDown(n, dp) << endl;
	cout << fiboBottomUp(n) << endl;
	cout << fiboBottomUpSpaceOptimised(n) << endl;

	// for(int i=0; i<dp.size(); i++) {
	// 	cout << dp[i] << " ";
	// }

	// cout << endl;

	return 0;
}