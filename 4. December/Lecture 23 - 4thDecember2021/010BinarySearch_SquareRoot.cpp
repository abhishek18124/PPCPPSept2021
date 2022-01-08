#include<iostream>

using namespace std;

int sqrt(int n) {
	int s = 0;
	int e = n;

	int ans = s;
	while(s <= e) {
		int m = (s+e)/2;
		if(m*m <= n) {
			ans = m;
			s = m+1;
		} else {
			e = m-1;
		}
	}
	return ans;
}

int main() {

	int n = 25;

	cout << sqrt(n) << endl;

	return 0;
}