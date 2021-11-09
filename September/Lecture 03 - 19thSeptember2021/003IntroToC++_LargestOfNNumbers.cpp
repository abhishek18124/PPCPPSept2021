#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;

	cout << "Enter the value of n = ";
	cin >> n;

	int largestNumberSeenSoFar = INT_MIN;

	int i = 1;

	int x;

	while(i <= n) {
		cout << "Enter the number " << i << "> ";
		cin >> x;
		if(x > largestNumberSeenSoFar) {
			largestNumberSeenSoFar = x;
		}
		i = i + 1;
	}

	cout << "Largest Number = " << largestNumberSeenSoFar << endl;

	return 0;
}