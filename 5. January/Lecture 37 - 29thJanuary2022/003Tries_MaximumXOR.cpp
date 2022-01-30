/*

Given an array of non-negative integers of size n, find the maximum possible XOR between 
any two numbers present in the array.

Example: 
	Input : A[] = {25, 10, 2, 8, 5, 3} 
	Output: 28 
	Explaination: The maximum result is 5 ^ 25 = 28 
	
	Input: A[] = {1, 2, 3, 4, 5, 6, 7} 
	Output: 7 
	Explaination: The maximum result is 1 ^ 6 = 7 

*/

#include<iostream>
#include<climits>

using namespace std;

class node {
public:
	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1
	
	node() {
		this->left = NULL;
		this->right= NULL;
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
			int bit = (1<<i)&n;
			if(!bit) {
				// ith bit of n is 0, check if temp node has a left child or not
				if(!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1, check if temp node has a right child or not
				if(!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	int helper(int n) {
		node* temp = root;
		int XOR = 0;
		int x_k = 0;
		for(int i=31; i>=0; i--) {
			int bit = (n>>i)&1;
			if(!bit) {
				// ith bit of n is 0
				if(temp->right) {
					// temp node has a right child i.e. a child node that contains 
					// complementary bit therefore the ith bit of XOR can be set
					XOR += (1<<i);
					temp = temp->right;
					x_k += (1<<i);
				} else {
					// temp node has a left child i.e. a child node that contains 
					// the same bit as n therefore the ith bit of XOR cannot be set
					temp = temp->left;
				}

			} else {
				// ith bit of n is 1
				if(temp->left) {
					// temp node has a left child i.e. a child node that contains 
					// complementary bit therefore the ith bit of XOR can be set
					XOR += (1<<i);
					temp = temp->left;
				} else {
					// temp node has a right child i.e. a child node that contains 
					// the same bit as n therefore the ith bit of XOR cannot be set
					temp = temp->right;
					x_k += (1<<i);
				}
			}
		}

		cout << n << "^" << x_k << " : " << XOR << endl;

		return XOR;
	}

	int maximumXOR(int X[], int n) {
		int finalAns = 0;
		for(int i=0; i<n; i++) {
			finalAns = max(finalAns, helper(X[i]));
		}
		return finalAns;
	}

};

int main() {

	int X[] = {10, 2, 8, 5, 3};
	int n = sizeof(X) / sizeof(int);

	trie t;

	for(int i=0; i<n; i++) {
		t.insert(X[i]);
	}

	cout << t.maximumXOR(X, n) << endl;
 
	return 0;
}



