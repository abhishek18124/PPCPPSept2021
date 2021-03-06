/*

given the pre-order traversal of a binary tree, design a recursive algorithm to 
compute its height
	 
	  height of a binary tree is equal to the height of the root node which is 
	  equal to the length of the longest path from the root node to a leaf node.

Example : Input  :10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output :3

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
		// x == -1 presents an empty tree
		return NULL;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right= buildTree();

	return root;
}

int height(node* root) {

	// base case
	if(root == NULL) {
		// you are trying to compute the height of an empty tree
		return -1;
	}

	// recursive case

	// 1. compute the height of the leftSubtree -- ask your friend
	int X = height(root->left);

	// 2. compute the height of the rightSubtree -- ask your friend
	int Y = height(root->right);

	return 1 + max(X, Y);
}

int main() {

	node* root = NULL;
	root = buildTree();
	cout << "height : " << height(root) << endl;
	return 0;
}

