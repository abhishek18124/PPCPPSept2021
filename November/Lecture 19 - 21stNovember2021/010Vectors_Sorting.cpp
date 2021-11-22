#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool myComparatorLesser(int a, int b) {
	return a < b;
}

bool myComparatorGreater(int a, int b) {
	return a > b;
}

int main() {

	vector<int> v = {1, 0, 2, 4, 3};

	for(int x : v) {
		cout << x << " ";
	}

	cout << endl;

	reverse(v.begin(), v.end());


	for(int x : v) {
		cout << x << " ";
	}

	cout << endl;

	// sort(v.begin(), v.end());

	// sort(v.begin(), v.end(), lesser<int>())

	sort(v.begin(), v.end(), myComparatorLesser);


	for(int x : v) {
		cout << x << " ";
	}

	cout << endl;

	// sort(v.rbegin(), v.rend());

	//sort(v.begin(), v.end(), greater<int>());

	sort(v.begin(), v.end(), myComparatorGreater);

	for(int x : v) {
		cout << x << " ";
	}

	cout << endl;


	return 0;
}