#include<iostream>

using namespace std;

int main() {

	int n = 50;

	for(int no=2; no <= n; no++) {
		// check if no is prime or not
		int i;
		for(i=2;i<=no-1; i++) {
			if(no%i == 0) {
				break;		
			}
		}
		if(i == no) {
			cout << no << " ";
		}

	}

	return 0;
}