/*

https://hack.codingblocks.com/app/contests/2625/1057/problem

When we calculate the mid point 'm', we ask the question 

	can 'k' painters paint 'n' boards of given 'len' in 'm' amt. of time ?
	
	now, we can rephrase this question in two ways 

	1. how many painters are required to paint 'n' boards of given 'len' in 'm' amt. of time ?
	
	   say, 'x' painters can paint 'n' boards of given 'len' in 'm' amt. of time then
	   
	   case (a)

	   now, if x <= k then that means 'k' painters can also paint 'n' boards of given 'len' 
	   in 'm' amt. of time so we get 'true' and move towards the left to minimize time
	
	   case (b)

	   if x > k then that means 'k' painters cannot paint 'n' boards of given 'len' in 'm'
	   amt. of time i.e we get false and move towards the right.

    2. how many boards of given 'len' can 'k' painters paint in 'm' amt. of time ? 

*/

#include<iostream>
#include<climits>

using namespace std;

int numOfPaintersRequired(int n, int* len, int timeLimit) {

	int numOfPainters = 1;
	int time = 0;
	for(int i=0; i<n; i++) {
		// paint the ith board
		time += len[i];
		if(time > timeLimit) {
			// increase the number of painters
			numOfPainters++;
			// restart the paint of the ith board
			time = len[i];
		}
	}
	return numOfPainters;

}


int getMinTime(int k, int n, int*len) {
	int s = INT_MIN; // 1 painter paints all the boards
	int e = 0; // for each board we assign a painter
	for(int i=0; i<n; i++) {
		s = max(s, len[i]);
		e += len[i];
	}  
	int ans = e;
	while(s <= e) {
		int m = s + (e-s)/2;
		int x = numOfPaintersRequired(n, len, m);
		if(x <= k) {
			// k painters can also paint n boards in m amt. of time
			ans = m;
			e = m-1;
		} else {
			// k painters cannot paint n boards in m amt. of time
			s = m+1;
		}
	}

	return ans;
}

int main() {

	int k;
	cin >> k;

	int n;
	cin >> n;

	int* len = new int[n];
	for(int i=0; i<n; i++) {
		cin >> len[i];
	}

	cout << getMinTime(k, n, len) << endl;

	return 0;
}