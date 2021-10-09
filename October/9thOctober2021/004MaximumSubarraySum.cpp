#include<iostream>
#include<climits>

using namespace std;

int main() {

	int A[] = {-4, 1, 3, -2, 6, -1, 4, -7};
	int n = sizeof(A) / sizeof(int);

	int maximumSubarraySumSoFar = INT_MIN;
	int start = -1;
	int end = -1;

	// Approach 1

	// // iterate over all the starting indices 
	// for(int i=0; i<n; i++) {
	// 	// for each starting index, iterate over all the ending indices
	// 	for(int j=i; j<n; j++) {
	// 		int sum = 0;
	// 		for(int k=i; k<=j; k++) {
	// 			sum += A[k];
	// 		}
	// 		if(sum > maximumSubarraySumSoFar) {
	// 			maximumSubarraySumSoFar = sum;
	// 			start = i;
	// 			end = j;
	// 		}

	// 	}
	// }

	// Approach 2

	// // iterate over all the starting indices 
	// for(int i=0; i<n; i++) {
	// 	// for each starting index, iterate over all the ending indices
	// 	int sum = 0;
	// 	for(int j=i; j<n; j++) {
	// 		sum += A[j];
	// 		if(sum > maximumSubarraySumSoFar) {
	// 			maximumSubarraySumSoFar = sum;
	// 			start = i;
	// 			end = j;
	// 		}

	// 	}
	// }

	// Approach 3 - using cumulative sum array

	int csum[n+1]={};
	for(int i=1; i<=n; i++) {
		csum[i] = csum[i-1] + A[i-1];
	}

	// for(int i=0; i<=n; i++) {
	// 	cout << csum[i] << " ";
	// }

	//cout << endl;

	// iterate over all the starting indices 
	for(int i=0; i<n; i++) {
		// for each starting index, iterate over all the ending indices
		for(int j=i; j<n; j++) {
			int sum = csum[j+1]-csum[i];
			if(sum > maximumSubarraySumSoFar) {
				maximumSubarraySumSoFar = sum;
				start = i;
				end = j;
			}
		}
	}



	for(int i=start; i<=end; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	cout << "The maximum subarray sum = " << maximumSubarraySumSoFar << endl;

	return 0;
}