#include<iostream>
#include<bitset>

using namespace std;

int main() {

	unsigned int x = 5;
	unsigned int y = 9;
	
	cout << bitset<32>(x) << " " << x << endl;
	cout << bitset<32>(y) << " " << y << endl;
	cout << bitset<32>(x&y) << " " << (x&y) << endl;

	cout << endl;

	cout << bitset<32>(x) << " " << x << endl;
	cout << bitset<32>(y) << " " << y << endl;
	cout << bitset<32>(x|y) << " " << (x|y) << endl;

	cout << endl;

	cout << bitset<32>(x) << " " << x << endl;
	cout << bitset<32>(y) << " " << y << endl;
	cout << bitset<32>(x^y) << " " << (x^y) << endl;

	cout << endl;


	cout << bitset<32>(x) << " " << x << endl;
	cout << bitset<32>(~x) << " " << (~x) << endl;

	
   
	return 0;
}