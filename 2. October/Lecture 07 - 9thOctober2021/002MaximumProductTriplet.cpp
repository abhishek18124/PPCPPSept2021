#include<iostream>
#include<climits>

using namespace std;

int main() {

	int A[] = {5, 0, -1, -2, 3};
	int n = sizeof(A) / sizeof(int);

	int firstLargest  = INT_MIN;
	int secondLargest = INT_MIN;
	int thirdLargest  = INT_MIN;

	int firstSmallest  = INT_MAX;
	int secondSmallest = INT_MAX;

	for(int i=0; i<n; i++) {
		if(A[i] > firstLargest) {
			thirdLargest = secondLargest;
			secondLargest = firstLargest;
			firstLargest = A[i];
		} else if(A[i] > secondLargest) {
			thirdLargest = secondLargest;
			secondLargest = A[i];
		} else if(A[i] > thirdLargest) {
			thirdLargest = A[i];
		}

		if(A[i] < firstSmallest) {
			secondSmallest = firstSmallest;
			firstSmallest = A[i];
		} else if(A[i] < secondSmallest) {
			secondSmallest = A[i];
		}
	}


	cout << firstLargest << " " << secondLargest << " " << thirdLargest << endl;
	cout << firstSmallest << " " << secondSmallest << endl;

	cout << max(firstLargest*secondLargest*thirdLargest, 
		        firstSmallest*secondSmallest*firstLargest) << endl;

	
	return 0;
}