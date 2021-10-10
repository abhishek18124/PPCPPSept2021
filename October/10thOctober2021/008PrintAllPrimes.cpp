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

void printAllPrimes(int N) {
	for(int no=2; no <=N; no++) {
		if(isPrime(no)) {
			cout << no << " ";
		}
	}

	cout << endl;
	
	return;
}

int main() {

	printAllPrimes(10);
		
	return 0;
}