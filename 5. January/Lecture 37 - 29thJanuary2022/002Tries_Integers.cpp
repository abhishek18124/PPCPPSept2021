/*

Implementation of the TRIE data structure to store non-negative integers.

Assume integer has 32-bit representation.

*/

#include<iostream>

using namespace std;

class node {

public: 
	node* left;
	node* right;

	node() {
		left = right = NULL;
	}
};


class trie {
	node* root;

public:

	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for(int i=31; i>=0; i--) {
			int bit = (n>>i)&1;
			if(!bit) {
				// ith bit of given integer n is not set i.e. 0
				if(!temp->left) {
					// temp node doesn't have a left child
					temp->left = new node();
				}
				temp = temp->left;
			} else {
				// ith bit of given integer n is set i.e. 1
				if(!temp->right) {
					// temp node doesn't have a right child
					temp->right = new node();
				}
				temp = temp->right;
			}
		}
	}

	bool search(int n) {
		node* temp = root;
		for(int i=31; i>=0; i--) {
			int bit = (n>>i)&1;
			if(!bit) {
				// ith bit of n is 0
				if(!temp->left) {
					// temp node doesn't have a left child i.e. it doesn't have a child node
					// with the bit value 0
					return false;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1
				if(!temp->right) {
					// temp node doesn't have a right child i.e. it doesn't have a child node
					// with bit value 1
					return false;
				}
				temp = temp->right;
			}
		}

		return true;
	}
};

int main() {

	int A[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(A) / sizeof(int);

	trie t;

	for(int i=0; i<n; i++) {
		t.insert(A[i]);
	}

	int B[] = {1, 2, 5, 10, 25, 0};
	int m = sizeof(B) / sizeof(int);

	for(int i=0; i<m; i++) {
		t.search(B[i]) ? cout << B[i] << " : true " << endl :
		                 cout << B[i] << " : false" << endl;
	}

	return 0;
}