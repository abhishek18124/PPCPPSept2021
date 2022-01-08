/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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

int findMinimum(node* root) {
	if(!root) {
		return INT_MAX;
	}

	while(root->left != NULL) {
		root = root->left;
	}

	return root->data;
}

int findMaximum(node* root) {
	if(!root) {
		return INT_MIN;
	}

	while(root->right != NULL) {
		root = root->right;
	}

	return root->data;
}

bool checkBST(node* root) {

	// base case 

	if(root == NULL) {
		// empty tree is a BST
		return true;
	}

	// recursive case

	// check if the leftSubtree is a BST -- ask your friend
	bool X = checkBST(root->left);

	// check if the rightSubtree is a BST -- ask your friend
	bool Y = checkBST(root->right);

	// check if the BST property is not violated at the root node
	bool Z = root->data > findMaximum(root->left) &&
	         root->data < findMinimum(root->right) ? true : false;

	return X && Y && Z;
}

class Triple {
public:
	bool isBST;
	int minVal;
	int maxVal;
};

Triple checkBSTEfficient(node* root) {

	Triple t;

	// base case 

	if(root == NULL) {
		// empty tree is a BST
		t.isBST = true;
		t.minVal = INT_MAX ;
		t.maxVal = INT_MIN ;
		return t;
	}

	// recursive case

	// check if the leftSubtree is a BST & simulataneously compute its max. & min. val -- ask your friend
	Triple tL = checkBSTEfficient(root->left);

	// check if the rightSubtree is a BST & simultaneously compute its max. and min. val.  -- ask your friend
	Triple tR = checkBSTEfficient(root->right);

	// check if the BST property is not violated at the root node
	bool Z = root->data > tL.maxVal &&
	         root->data < tR.minVal ? true : false;

	t.isBST = tL.isBST && tR.isBST && Z;
	t.minVal = min(root->data, tL.minVal);
	t.maxVal = max(root->data, tR.maxVal);

	return t;
}

bool checkBSTRangeEfficient(node* root, int lb, int ub) {

	// base case
	
	if(root == NULL) {
		// empty tree is a BST
		return true;
	}
	
	// recursive case

	if(root->data > lb && root->data < ub &&
	   checkBSTRangeEfficient(root->left, lb, root->data) &&
	   checkBSTRangeEfficient(root->right, root->data, ub)) {
		return true;
	}

	return false;

}

int main() {

	node* root = new node(10);
	
	root->left = new node(5);
	root->left->left  = new node(3);
	root->left->right = new node(7);

	root->right = new node(15);
	root->right->left  = new node(13);
	root->right->right = new node(17);

	checkBST(root) ? cout << "true" << endl :
					 cout << "false" << endl;

	checkBSTEfficient(root).isBST ? cout << "true" << endl :
					                cout << "false" << endl;

	checkBSTRangeEfficient(root, INT_MIN, INT_MAX) ? cout << "true" << endl :
					               cout << "false" << endl;

	return 0;
}