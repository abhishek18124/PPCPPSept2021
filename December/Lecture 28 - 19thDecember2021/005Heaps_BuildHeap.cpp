/*

	Given an array of n integers, design a O(n) algorirthm to build a max_heap.

*/

#include<iostream>

using namespace std;

void heapify(int* v, int n, int i) {
		int max_idx = i; // assume node at the ith index is the maximum
		int left_idx= 2*i;

		if(left_idx < n && v[left_idx] > v[max_idx]) {
			max_idx = left_idx;
		}

		int right_idx = 2*i + 1;
		if(right_idx < n && v[right_idx] > v[max_idx]) {
			max_idx = right_idx;
		}

		if(max_idx != i) {
			swap(v[max_idx], v[i]);
			heapify(v, n, max_idx);
		}

}

int main() {
	
	int v[] = {-1, 6, 8, 3, 5, 4, 9, 7, 2, 0, 1};
	int n = sizeof(v) / sizeof(int) ;

	for(int i=n/2; i>=1; i--) {
		heapify(v, n, i);
	}

	for(int i=1; i<n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}