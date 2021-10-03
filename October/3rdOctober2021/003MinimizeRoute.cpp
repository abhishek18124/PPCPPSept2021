#include<iostream>
#include<cmath>

using namespace std;

int main() {

	char ch;

	int x = 0;
	int y = 0;

	while(true) {
		ch = cin.get();

		if(ch == '\n') {
			break;
		}

		if(ch == 'N') {
			y++;
		} else if(ch == 'S') {
			y--;
		} else if(ch == 'E') {
			x++;
		} else if(ch == 'W') {
			x--;
		}
	}

	cout << "(x, y) = " << x << ", " << y << endl;

	if(x >= 0 && y >= 0) {
		// you're in the 1st quadrant

		// print x times E
		for(int i=1; i<=x; i++) {
			cout << 'E';
		}

		// print y times N
		for(int i=1; i<=y; i++) {
			cout << 'N';
		}
	} else if(x <= 0 && y >= 0) {
		// you're in the 2nd quadrant

		// print y times N
		for(int i=1; i<=y; i++) {
			cout << 'N';
		}

		// print |x| times W
		for(int i=1; i<=abs(x); i++) {
			cout << 'W';
		}

	} else if(x <= 0 && y <= 0) {
		// you're in the 3rd quadrant

		// print |y| times S
		for(int i=1; i<=abs(y); i++) {
			cout << 'S';
		}

		// print |x| times W
		for(int i=1; i<=abs(x); i++) {
			cout << 'W';
		}
	} else {
		// you're in the 4th quadrant

		// print x times E
		for(int i=1; i<=x; i++) {
			cout << 'E';
		}

		// print |y| times S
		for(int i=1; i<=abs(y); i++) {
			cout << 'S';
		}
	}

	return 0;
}