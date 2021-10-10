#include<iostream>

using namespace std;

void greet() {
	cout << "Hello from inside the greet function" << endl;
	return; // optional  
}

int main() {

	cout << "Before the function call" << endl;
	greet(); // call/invocation to the greet function
	cout << "After the function call" << endl;

	return 0;
}