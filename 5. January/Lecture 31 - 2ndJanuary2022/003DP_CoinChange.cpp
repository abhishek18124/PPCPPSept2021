/*

You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.Return the fewest number 
of coins that you need to make up that amount. 

You may assume that you have an infinite number of each kind of coin.

Don't forget to handle the case if that amount of money cannot be made up by any 
combination of the coins.

Example 1:

	Input: coins = [1,2,5], amount = 11
	Output: 3

	Input: coins = [3, 6], amount = 13
	Output: - 

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minCoins(int n, vector<int>& c) {

	// base case
	if(n == 0) {
		return 0;
	}

	// recursive case
	int ans = INT_MAX;
	int k = c.size();

	for(int j=0; j<k; j++) {
		if(n-c[j] >= 0) {
			ans = min(ans, minCoins(n-c[j], c));
		}
	}

	return ans == INT_MAX ? INT_MAX : 1 + ans;

}

int minCoinsBottomUp(int n, vector<int>& c) {

	vector<int> dp(n+1);
	int k = c.size();

	dp[0] = 0; // at the 0th index, we have the base case

	for(int i=1; i<=n; i++) {
		// dp[i] is the result of the subproblem f(i) i.e.
		// min. no. of coins required to reduce amt. i to 0

		int ans = INT_MAX;
		for(int j=0; j<k; j++) {
			if(i-c[j] >= 0) {
				ans = min(ans, dp[i-c[j]]);
			}
		}

		dp[i] = ans == INT_MAX ? INT_MAX : 1 + ans;
	}

	return dp[n];

} 


int main() {

	int n = 13;
	vector<int> c = {3, 6};

	cout << minCoins(n, c) << endl;
	cout << minCoinsBottomUp(n, c) << endl;

	return 0;
}