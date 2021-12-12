/*

given the pre-order traversal of a binary tree, design a recursive 
algorithm to mirror it.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 10 30 60 -1 -1 -1 20 50 -1 70 -1 -1 40 -1 -1 
                  
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
		return NULL;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right= buildTree();

	return root;
}

void preorder(node* root) {
	if(root == NULL) {
		// root represents an empty tree
		cout << "-1 ";
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

node* mirror(node* root) {
	if(root == NULL) {
		// you are trying to mirror an empty tree
		return NULL;
	}

	// recursive case

	// 1. mirror the leftSubtree -- ask your friend
	root->left = mirror(root->left);

	// 2. mirror the rightSubtree-- ask your friend
	root->right = mirror(root->right);

	// 3. swap root's left child with the right child
	swap(root->left, root->right);

	return root;
}

int main() {

	node* root = NULL;
	root = buildTree();
	root = mirror(root);
	preorder(root);
	
	return 0;
}