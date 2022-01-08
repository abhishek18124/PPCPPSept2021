/*

Given the pre-order traversal of a binary tree, design a recursive algorithm to 
compute the sum of nodes inside the binary tree

Example : Input  :10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 280
*/

#include<iostream>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

node* buildTree() {
	int x;
	cin >> x;

	if(x == -1) {
		node* root = NULL;
		// root represent an empty tree
		return root;
	}

	node* root  = new node(x);
	root->left  = buildTree();
	root->right = buildTree();

	return root;

}

int computeSum(node* root) {
	// base case
	if(root == NULL) {
		// you've to compute the sum of nodes in an empty tree
		return 0;
	}

	// recursive case 

	// 1. compute the sum of nodes in the left subtree -- ask your friend
	int X = computeSum(root->left);

	// 2. compute the sum of nodes in the right subtree -- ask your friend
	int Y = computeSum(root->right);

	return X + Y + root->data;

}

int main() {

	node* root = NULL;
	root = buildTree();
	cout << "sum : " << computeSum(root) << endl;

	return 0;
}

