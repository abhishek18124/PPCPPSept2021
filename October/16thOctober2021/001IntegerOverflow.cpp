#include<iostream>
#include<climits>

#define ll long long

using namespace std;

int main() {

	ll x = INT_MAX; // long long int or long long are the same; 8B are reserved
				    // therefore, you can store numbers in the range -2^63 to 
					// 2^63-1

	cout << x + 1 << endl;



	return 0;
}