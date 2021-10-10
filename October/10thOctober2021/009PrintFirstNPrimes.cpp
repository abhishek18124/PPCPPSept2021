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

void printNPrimes(int N) {
	
	int cnt = 0;
	int no = 2;

	while(cnt < N) {
		if(isPrime(no)) {
			cout << no << " ";
			cnt++;
		}
		no++;
	}

	cout << endl;

	return;
}

int main() {

	int N = 15;
	printNPrimes(N);
		
	return 0;
}