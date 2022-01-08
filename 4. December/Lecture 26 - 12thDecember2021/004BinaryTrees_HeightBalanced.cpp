
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example 
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

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

int height(node* root) {
	if(root == NULL) {
		return -1;
	}

	int hL = height(root->left);
	int hR = height(root->right);

	return 1 + max(hL, hR);

}

node* buildTree() {
	int x;
	cin >> x;

	if(x == -1) {
		node* root = NULL;
		// root represents an empty tree
		return root;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right=buildTree();

	return root;
}

bool checkBalance(node* root) {

	// base case
	if(!root) {
		// empty tree is balanced 
		return true;
	}

	// recursive case

	// 1. check if the leftSubtree is balanced -- ask your friend
	bool X = checkBalance(root->left);

	// 2. check if the rightSubtree is balanced -- ask your friend
	bool Y = checkBalance(root->right);

	// 3. check if the root node is balanced
	bool Z = abs(height(root->left)-height(root->right)) <= 1 ? true : false;

	return X && Y && Z;
}

class Pair {
public: 
	bool isBalanced;
	int height;
};

Pair checkBalanceEfficient(node* root) {

	Pair p;

	// base case
	if(!root) {
		// empty tree is balanced & has heigh equal to -1
		p.isBalanced = true;
		p.height = -1;
		return p;
	}

	// recursive case

	// 1. check if the leftSubtree is balanced & also compute its height -- ask your friend
	Pair pL = checkBalanceEfficient(root->left);

	// 2. check if the rightSubtree is balanced & also compute its height -- ask your friend
	Pair pR = checkBalanceEfficient(root->right);

	// 3. check if the root node is balanced
	bool Z = abs(pL.height-pR.height) <= 1 ? true : false;

	p.isBalanced = pL.isBalanced && pR.isBalanced && Z;
	p.height = 1 + max(pL.height, pR.height);

	return p;
}



int main() {

	node* root = NULL;
	root = buildTree();

	checkBalance(root) ? cout << "true" << endl : 
						 cout << "false" << endl;

	checkBalanceEfficient(root).isBalanced ? cout << "true" << endl :
						                     cout << "false" << endl;
 	
 	return 0;
 }