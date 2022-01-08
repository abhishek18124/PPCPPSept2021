/*

Given a sorted array containing n distinct elements, and a target write a function which 
prints all pairs of numbers in the given array which sum to target.

Example :
	Input  : A[] = {1, 2, 3, 4, 5} Target = 5
	Output : {1, 4}, {2, 3}

*/

#include<iostream>

using namespace std;

// // Approach 1 - n^2 steps we analyse all the nc2 pairs

// int computePairs(int A[], int n, int t) {

// 	int count = 0;

// 	// iterate over the starting indices of the pair
// 	for(int i=0; i<n-1; i++) {
// 		// iterate over the ending indices of the pair
// 		for(int j=i+1; j<n; j++) {
// 			if(A[i]+A[j] == t) {
// 				// the ith and the jth element form a valid pair
// 				cout << A[i] << " " << A[j] << endl;
// 				count++;
// 			}
// 		}
// 	}

// 	return count;
// }

// Approach 2 - using Binary Search (nlong) H.W.

// Approach 3 - using two pointer approach 

int computePairsEfficient(int A[], int n, int t) {
	int i = 0;
	int j = n-1;
	int count = 0;
	while(i < j) {
		int s = A[i]+A[j];
		if(s == t) {
			// you've found a pair at the ith and jth index
			count++;
			cout << A[i] << " " << A[j] << endl;
			i++;
			j--;
		} else if(s > t) {
			// jth element is of no use
			j--;
		} else {
			// ith element is of no use
			i++;
		}
	}

	return count;
}



int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);
	int t = 6;

	// cout << computePairs(A, n, t) << endl;
	cout << computePairsEfficient(A, n, t) << endl;

	return 0;
}