#include<iostream>

using namespace std;

int main() {

 	int* ptr = new int; // This will allocate 4B of memory on the heap segment
 			            // to store an integer and return its starting address

 	*ptr = 10;

 	cout << "value at ptr = " << *ptr << endl;

 	delete ptr;

 	ptr = NULL;

	// cout << "value at ptr = " << *ptr << endl;

	return 0;
}