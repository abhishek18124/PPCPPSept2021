#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int* xptr = &x;

	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "&x = " << &x << endl;
	cout << "sizeof(&x) = " << sizeof(&x) << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << endl;
	cout << "*xptr = " << *xptr << endl;

	int* aptr = xptr;
	cout << "aptr = " << aptr << endl;
	cout << "sizeof(aptr) = " << sizeof(aptr) << endl;


	cout << endl;
	
	double y = 12.5;
	double* yptr = &y;

	cout << "y = " << y << endl;
	cout << "sizeof(y) = " << sizeof(y) << endl;
	cout << "&y = " << &y << endl;
	cout << "sizeof(&y) = " << sizeof(&y) << endl;
	cout << "yptr = " << yptr << endl;
	cout << "sizeof(yptr) = " << sizeof(yptr) << endl;
	cout << "*yptr = " << *yptr << endl;

	cout << endl;

	char z = 'A';
	char* zptr = &z;

	cout << "z = " << z << endl;
	cout << "sizeof(z) = " << sizeof(z) << endl;
	cout << "&z = " << &z << endl;
	cout << "sizeof(&z) = " << sizeof(&z) << endl;
	cout << "zptr = " << zptr << endl;
	cout << "sizeof(zptr) = " << sizeof(zptr) << endl;
	cout << "*zptr = " << *zptr << endl;


	return 0;
}