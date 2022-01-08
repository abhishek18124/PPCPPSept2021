#include<iostream>

using namespace std;

int* resize(int* A, int size) {
	cout << "I am resizing the given array from " << size*sizeof(int) << "B to " << 2*size*sizeof(int) << "B" << endl;
	int* B = new int[size*2];
	for(int i=0; i<size; i++) {
		B[i] = A[i];
	}
	delete[] A;
	return B;
}

int main() {

	int size = 1;
	int* A = new int[size];
		
	int no;
	cin >> no;

	int i = 0;

	while(no != -1) {
		A[i] = no;
		i++;
		if(i == size) {
			A = resize(A, size);
			size *= 2;
		}
		cin >> no;
	}

	for(int j=0; j<i; j++) {
		cout << A[j] << " ";
	}

	cout << endl;

	return 0;
}