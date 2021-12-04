/*

https://www.spoj.com/problems/AGGRCOW/

*/

#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

bool canPlaceCows(int n, int c, int* pos, int m) {
	// place the 1st cow in the 1st stall
	int numOfCowsPlaced = 1;
	int prevCowPosition = pos[0];

	for(int i=1; i<n; i++) {
		// check if you can place the next cow in the ith stall or not
		if(pos[i]-prevCowPosition >= m) {
			// place the next cow in the ith stall
			numOfCowsPlaced++;
			prevCowPosition = pos[i];
			if(numOfCowsPlaced == c) {
				return true;
			}
		}
	}
	return false;
}

int largestMinDist(int n, int c, int* pos) {

	int s = INT_MAX; // place the two cows in stalls closest to each other
	for(int i=1; i<n; i++) {
		if(pos[i]-pos[i-1] < s) {
			s = pos[i]-pos[i-1];
		}
	}

	int e = pos[n-1]-pos[0]; // place the two at extreme positions

	int ans = s;

	while(s <= e) {
		int m = s + (e-s)/2;
		if(canPlaceCows(n, c, pos, m)) {
			// you can place C cows in N stalls at a min-dist of >= m
			// since you want to maximize the ans, continue your search
			// in [m+1, e]
			ans = m;
			s = m+1;
		} else {
			// you cannot place C cows in N stalls so continue your 
			// search towards the left of m i.e. [s, m-1]
			e = m-1;
		}
	}

	return ans;

}

int main() {

	int t;
	cin >> t;

	int n, c;
	int* pos = new int[n];

	while(t--) {
		cin >> n >> c;
		for(int i=0; i<n; i++) {
			cin >> pos[i];
		}
		sort(pos, pos+n);
		cout << largestMinDist(n, c, pos) << endl;
	}	

	// int n = 5;
	// int c = 3;
	// int pos[] = {1, 2, 4, 8, 9};
	// cout << largestMinDist(n, c, pos) << endl;

	return 0;
}