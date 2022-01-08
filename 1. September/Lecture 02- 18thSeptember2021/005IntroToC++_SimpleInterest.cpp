#include<iostream>

using namespace std;

int main() {

	int p, r, t;

	cout << "Enter principle = ";
	cin >> p;

	cout << "Enter rate = ";
	cin >> r;

	cout << "Enter time = ";
	cin >> t;

	float si = (p * r * t) / 100.0;

	cout << "Simple interest = "<< si << endl;

	return 0;
}