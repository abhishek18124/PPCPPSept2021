/*

You are packing for a vacation on the sea side and you are going to carry only one bag with 
capacity C (1 <= C <= 1000). You also have N (1<= N <= 1000) items that you might want to take 
with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will 
have to choose. For each item you are given its size and its value. You want to maximize the total 
value of all the items you are going to bring. What is this maximum total value?

Example :
	Input : N = 5, W = 4
			weights[] = {1, 2, 3, 2, 2}
			profits[] = {8, 4, 1, 5, 3}
	Output: 13

*/


#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& weights, vector<int>& profits, int N, int j, int w) {

	// base case
	if(j == N) {
		// how much profit you can make given you are left with no object
		return 0;
	}

	if(w == 0) {
		// how much profit you can make given a knapsack of 0 capacity
		return 0;
	}

	// recursive case

	if(weights[j] > w) {
		// you've no option but to exclude the jth object
		return maxProfit(weights, profits, N, j+1, w);
	}

	// you've to decide for the jth object if you want to incl. the
	// jth obj. in the knapsack or exclude the jth obj. from the knapsack

	// 1. include the jth object
	int X = maxProfit(weights, profits, N, j+1, w-weights[j]);

	// 2. exclude the jth object
	int Y = maxProfit(weights, profits, N, j+1, w);

	return max(profits[j]+X, Y);

}

int maxProfitBottomUp(vector<int>& weights, vector<int>&  profits, int N, int W) {

	vector<vector<int>> dp(N+1, vector<int>(W+1));

	// base case
	for(int j=0; j<=N; j++) {
		dp[j][0] = 0;
	}

	for(int w=0; w<=W; w++) {
		dp[N][w] = 0;
	}

	for(int j=N-1; j>=0; j--) {
		for(int w=1; w<=W; w++) {
			if(weights[j] > w) {
				dp[j][w] = dp[j+1][w];
			} else {
				dp[j][w] = max(profits[j] + dp[j+1][w-weights[j]],
					                        dp[j+1][w]);
			}
		}
	}

	return dp[0][W];

}

int main() {

	int N = 5;
	int W = 4;

	vector<int> weights = {1, 2, 3, 2, 2};
	vector<int> profits = {8, 4, 1, 5, 3};

	cout << maxProfit(weights, profits, N, 0, W) << endl;
	cout << maxProfitBottomUp(weights, profits, N, W) << endl;
	
	return 0;
}