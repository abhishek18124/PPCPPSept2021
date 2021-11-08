/*

You are packing for a vacation on the sea side and you are going to carry only one bag with 
capacity C (1 <= C <= 1000). You also have N (1<= N <= 1000) items that you might want to take 
with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will 
have to choose. For each item you are given its size and its value. You want to maximize the total 
value of all the items you are going to bring. What is this maximum total value?

Example :
	Input : N = 5 C = 4
			P = {8, 4, 0, 5, 3}
			W = {1, 2, 3, 2, 2}
			
	Output: 13

*/



#include<iostream>

using namespace std;

int maxProfit(int* profits, int* weights, int n, int i, int w) {
	if(i == n || w == 0) {
		return 0;
	}

	if(weights[i] <= w) {
		// you've an option to include or exclude the ith object from the knapsack

		// let us say you decide to include the ith object
		int x1 = maxProfit(profits,  weights, n, i+1, w-weights[i]);

		// let us say you decide to exclude the ith object
		int x2 = maxProfit(profits, weights, n, i+1, w);

		return max(profits[i]+x1, x2);
	} 

	// you've no option but to exclude the ith object
	return maxProfit(profits, weights, n, i+1, w);
}

int main() {
	
	int n = 5;
	int W = 4;
	
	int profits[] = {8, 4, 0, 5, 3};
	int weights[] = {1, 2, 3, 2, 2};

	cout << maxProfit(profits, weights, n, 0, W) << endl;
			
	return 0;
}