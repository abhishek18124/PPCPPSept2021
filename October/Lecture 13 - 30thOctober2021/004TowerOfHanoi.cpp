#include<iostream>

using namespace std;

void f(int n, char src, char dst, char hlp) {
	if(n == 0) {
		return;
	}

	f(n-1, src, hlp, dst);
	cout << "Move disk from " << src << " to " << dst << endl;
	f(n-1, hlp, dst, src);
}

int main() {

	int n = 3;

	f(n, 'S', 'D', 'H');

	return 0;
}