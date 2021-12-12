/*

given the pre-order traversal of a binary tree, design a recursive algorithm 
to compute its diameter

	  diameter of a binary tree is the length of the longest path between any 
	  two nodes in the binary tree.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 5

          Input  : 10 20 30 50 -1 -1 -1 40 -1 60 -1 -1 70 -1 -1
          Output : 4
          
          Input  : 10 20 -1 -1 30 40 60 -1 -1 -1 50 -1 70 -1 -1
          Output : 4
          
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
	if(root == NULL) {
		// root represents an empty tree
		return -1;
	}

	int hL = height(root->left);
	int hR = height(root->right);
	return 1 + max(hL, hR);
}

int computeDiameter(node* root) {

	if(root == NULL) {
		// compute the diameter of an empty tree
		return 0;
	}

	// recursive case

	// 1. compute the diameter of the leftSubtree -- ask your friend
	int X = computeDiameter(root->left);

	// 2. compute the diamter of the rightSubtree -- ask your friend
	int Y = computeDiameter(root->right);

	// 3. compute the length of the longest path that passes through the root
	int Z = height(root->left) + height(root->right) + 2;

	return max(X, max(Y, Z));
}

class Pair {
public:
	int diameter;
	int height;
};

Pair computeDiameterEfficient(node* root) {

	Pair p;

	if(root == NULL) {
		// compute the diameter & height of an empty tree
		p.height = -1;
		p.diameter = 0;
		return p;
	}

	// recursive case

	// 1. compute the diameter & height of the leftSubtree simultaneously -- ask your friend
	Pair pL = computeDiameterEfficient(root->left);

	// 2. compute the diamter & height of the rightSubtree simultaneously -- ask your friend
	Pair pR = computeDiameterEfficient(root->right);

	// 3. compute the length of the longest path that passes through the root
	int Z = pL.height + pR.height + 2;

	p.height = 1 + max(pL.height, pR.height);
	p.diameter = max(pL.diameter, max(pR.diameter, Z));

	return p;
}



int main() {

	node* root = NULL;
	root = buildTree();
	cout << "diameter : " << computeDiameter(root) << endl;
	cout << "diameter : " << computeDiameterEfficient(root).diameter << endl;

	return 0;
}

