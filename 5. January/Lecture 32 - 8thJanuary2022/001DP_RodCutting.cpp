/*

Given a rod of length 'n' along with prices of its pieces of different lengths, design an algorithm to 
compute the maximum profit we can make by cutting the rod and a selling its pieces. 

Example :
	
	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [1,  5,  8,  9,  10, 17, 17, 20]
	Output : 22

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [3,  5,  8,  9, 10, 17, 17, 20]
	Output : 24

	
*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxProfit(int n, vector<int>& prices) {
	// base case
	if(n == 0) {
		// given a rod of length 0, what is the max. profit you can make ?
		return 0;
	}

	// recursive case
	int ans = INT_MIN;
	for(int j=1; j<=n; j++) {
		if(n-j >= 0) {
			// you can make a cut of size 'j' given a rod of length 'n'
			ans = max(ans, prices[j-1] + maxProfit(n-j, prices));
		}
	}

	return ans;
}

int maxProfitTopDown(int n, vector<int>& prices, vector<int>& dp) {
	// base case
	if(n == 0) {
		// given a rod of length 0, what is the max. profit you can make ?
		return dp[n]=0;
	}

	// lookup
	if(dp[n] != -1) {
		return dp[n];
	}

	// recursive case
	int ans = INT_MIN;
	for(int j=1; j<=n; j++) {
		if(n-j >= 0) {
			// you can make a cut of size 'j' given a rod of length 'n'
			ans = max(ans, prices[j-1] + maxProfitTopDown(n-j, prices, dp));
		}
	}

	return dp[n]=ans;
}

int maxProfitBottomUp(int n, vector<int>& prices) {

	vector<int> dp(n+1);

	// base case
	dp[0] = 0;

	// recursive case
	for(int i=1; i<=n; i++) {
		int ans = INT_MIN;
		for(int j=1; j<=i; j++) {
			if(i-j >= 0) {
				// you can make a cut of size 'j' given a rod of length 'i'
				ans = max(ans, prices[j-1] + dp[i-j]);
			}
		}
		dp[i]=ans;
	}

	return dp[n];

}

int main() {

	vector<int> prices = {3,  5,  8,  9, 10, 17, 17, 20};
	int n = prices.size();
		
	cout << maxProfit(n, prices) << endl;

	vector<int> dp(n+1, -1);
	cout << maxProfitTopDown(n, prices, dp) << endl;
	cout << maxProfitBottomUp(n, prices) << endl;

	return 0;
}