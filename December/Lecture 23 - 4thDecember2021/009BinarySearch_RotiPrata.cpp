/* 

https://www.spoj.com/problems/PRATA/

When we calculate the mid point 'm', we ask the question 

	can 'l' cooks with given ranks cook 'p' pratas in 'm' amt. of time ?
	
	now, we can rephrase this question in two ways 

	1. how many pratas can 'l' cooks cook in 'm' amt. of time ? 
	   say, 'l' cooks can cook 'x' pratas in 'm' amt. of time
	   
	   case (a)

	   now, if x >= p (initial requirement) then that means 'l' cooks 
	   can also cook 'p' pratas in 'm' amt. of time so  we get 'true' 
	   and move towards the left to minimize time
	
	   case (b)

	   if x < p then that means 'l' cooks cannot cook 'p' pratas in 'm'
	   amt. of time i.e we get false and move towards the right.

	2. how many cooks are required to cook 'p' pratas in 'm' amt. of time ?

	   the problem with asking this question is that we cannot implement it.
	   why ? because in the question we associate a rank with each cook, so
       if we were to implement this function we need know the ranks of cooks
       that we do not know.
	   
	   try to implement this function, and you'll understand the problem :)	


*/

#include<iostream>
#include<climits>

using namespace std;

int getMinTime(int p, int l, int* ranks) {
	int s = ?;
	int e = ?;
	int ans = e;
	while(s <= e) {
		int m = s+(e-s)/2;
		if(?) {

		} else {

		}
	}
	return ans;
}

int main() {

	int t;
	cin >> t;

	int p, l;
	int* ranks = new int[l];

	while(t--) {
		cin >> p >> l;
		for(int i=0; i<l; i++) {
			cin >> ranks[i];
		}
		cout << getMinTime(p, l, ranks) << endl;
	}

	return 0;
}

