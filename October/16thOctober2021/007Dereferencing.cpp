#include<iostream>

using namespace std;

int main() {

	int x = 516;
	int* xptr = &x;
	char* chptr = (char*)&x;

	cout <<  *xptr << endl;
	cout << int(*chptr) << endl;

	return 0;
}