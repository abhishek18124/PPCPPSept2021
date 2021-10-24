#include<iostream>

using namespace std;

int main() {

	pair<int, int> p1;

	p1 = make_pair(1, 2);

	cout << p1.first << " " << p1.second << endl;

	pair<int, int> p2 = {3, 4};

	cout << p2.first << " " << p2.second << endl;

	return 0;
}