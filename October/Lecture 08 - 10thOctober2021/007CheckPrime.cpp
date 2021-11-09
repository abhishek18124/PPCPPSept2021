#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	int n = 22;

	isPrime(n) ? cout << n << " is a prime" << endl : cout << n << " is not prime" << endl;

	return 0;
}