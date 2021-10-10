#include<iostream>

using namespace std;

bool isEven(int n) {
	// if(n%2 == 0) {
	// 	return true;
	// } else {
	// 	return false;
	// }

	return n%2 == 0;
}

int main() {

	//bool result = isEven(34);

	// if(result == true) {
	// 	cout << "Even" << endl;
	// } else {
	// 	cout << "Odd" << endl;
	// }

	// if(result) {
	// 	cout << "Even" << endl;
	// } else {
	// 	cout << "Odd" << endl;
	// }

	// result ? cout << "Even" : cout << "Odd";

	// if(isEven(4)) {
	// 	cout << "Even" << endl;
	// } else {
	// 	cout << "Odd" << endl;
	// }

	isEven(4) ? cout << "Even" : cout << "Odd";


	return 0;
}