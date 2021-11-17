#include<iostream>

using namespace std;

int main() {

	// int* ptr = new int[5];

	cout << "Enter the value of n = ";
	int n;

	cin >> n;

	int* ptr = new int[n];

	for(int i=0; i<5; i++) {
		cin >> ptr[i]; // or cin >> *(ptr+i)
	}

	for(int i=0; i<5; i++) {
		cout << ptr[i] << " "; // or cout << *(ptr+i)
	}

	delete [] ptr;

	ptr = NULL; // just for safety

	return 0;
}