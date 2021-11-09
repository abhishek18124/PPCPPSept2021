#include<iostream>

using namespace std;

int main() {

	int n = 24;

	float i = 0;
	float inc = 1;
	int p = 6;

	for(int j=0; j<=p; j++) {
		while(i*i <= n) {
			i = i + inc;
		}

		i = i - inc;
		inc = inc / 10;
	}

	cout << i << endl;

	return 0;
}