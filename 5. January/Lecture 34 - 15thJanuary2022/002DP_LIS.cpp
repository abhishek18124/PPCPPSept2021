/*

Given an integer array 'nums', return the length of the longest increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without 
changing the order of the remaining elements. 

Example 1:
	Input: nums[] = [10, 9, 2, 5, 3, 7, 18]
	Output: 4
	Explanation: The longest increasing subsequence is [2, 5, 7, 18], therefore the output is 4.

Example 2:
	Input: nums[] = [0,1,0,3,2,3]
	Output: 4
	Explanation: The longest increasing subsequence is [0, 1, 2, 3], therefore the output is 4.
*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int lis_k(vector<int>& A, int n, int i) {

	// base case
	if(i == n-1) {
		// compute the length of the LIS starting the (n-1)th idx
		return 1;
	}

	// recursive case

	int ans = INT_MIN;
	for(int j=i+1; j<n; j++) {
		if(A[j] > A[i]) {
			// A[j] is a valid candidate to be  the 
			// next element that can come after the
			// element at the ith idx

			// compute the length of the LIS starting
			// at the jth idx -- ask your friend
			ans = max(ans, lis_k(A, n, j));
		}
	}

	return ans == INT_MIN ? 1 : 1 + ans;
}

int lis(vector<int>& A, int n) {

	int finalAns = INT_MIN;
	for(int k=0; k<n; k++) {
		finalAns = max(finalAns, lis_k(A, n, k));
	}
	return finalAns;

}

int lis_bottom_up(vector<int>& A, int n) {
	vector<int> dp(n);

	// base case
	dp[n-1] = 1;

	// recursive case
	for(int i=n-1; i>=0; i--) {
		int ans = INT_MIN;
		for(int j=i+1; j<n; j++) {
			if(A[j] > A[i]) {
				// A[j] is a valid candidate to be  the 
				// next element that can come after the
				// element at the ith idx
				ans = max(ans, dp[j]);
			}
		}
		dp[i] = ans == INT_MIN ? 1 : 1 + ans;
	}

	int finalAns = INT_MIN;
	int maxIndex = 0;
	for(int i=0; i<n; i++) {
		if(dp[i] > finalAns) {
			finalAns = dp[i];
			maxIndex = i;
		}
	}

	int m = finalAns;
	vector<int> lis;

	lis.push_back(A[maxIndex]);
	m--;

	int lastElement = A[maxIndex];
	int lastElementIndex = maxIndex;

	while(m != 0) {
		for(int i=lastElementIndex+1; i<n; i++) {
			if(A[i] > lastElement && dp[i] == m) {
				lis.push_back(A[i]);
				lastElement = A[i];
				lastElementIndex = i;
				m--;
				break;
			}
		}
	}

	for(int i=0; i<lis.size(); i++) {
		cout << lis[i] << " ";
	}

	cout << endl;

	return finalAns;
}


int main() {

	vector<int> A = {0,1,0,3,2,3};
	int n = A.size();

	cout << lis(A, n) << endl;
	cout << lis_bottom_up(A, n) << endl;
	
	return 0;
}