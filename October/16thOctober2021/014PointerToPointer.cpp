#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int* xptr = &x;
	int** xxptr = &xptr;
	int*** xxxptr = &xxptr;

	cout << *xptr << endl;
	cout << **xxptr << endl;
	cout << ***xxxptr << endl;

	void* voidptr = &x;

	char ch = 'A';
	cout << (void*)&ch << endl;


	return 0;
}