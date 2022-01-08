#include<iostream>

using namespace std;

class Test {
public:
	int* x;

	Test() {
		x  = new int;
		*x = 10;
	}

	int f1() {
		return *x; // dereference x and return its value
	}

	int& f2() {
		return *x; 
	}
	
};

int main() {

	Test t;

	int x1 = t.f1();
	cout << "x1 = " << x1 << endl;

	int x2 = t.f2();
	cout << "x1=" << x1 << ", x2=" << x2 << endl;

	// when a value is returned by reference, we can assign values to it since it 
	// is just a new variable name
	t.f2() = 50;
	x1 = t.f1();
	x2 = t.f2();
	cout << "x1=" << x1 << ", x2=" << x2 << endl;

	return 0;
}
