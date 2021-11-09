#include<iostream>

using namespace std;

int main() {
	
	int x = 10;
	int* xptr = &x;
	double* dptr = (double*)&x; // char*(&x)

	cout << xptr << endl;
	cout << dptr << endl;

	char ch = 'A';
	char* chptr = &ch;

	cout << (int *)chptr << endl;

	return 0;
}