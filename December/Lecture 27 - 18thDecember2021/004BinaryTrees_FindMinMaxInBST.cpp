/*

	Given a BST, design an algorithm to find the minimum and the maximum value inside it.

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

node* findMinimum(node* root) {
	if(!root) {
		return NULL;
	}

	while(root->left != NULL) {
		root = root->left;
	}

	return root;
}

node* findMaximum(node* root) {
	if(!root) {
		return NULL;
	}

	while(root->right != NULL) {
		root = root->right;
	}

	return root;
}

int main() {

	node* root = new node(10);
	
	root->left = new node(5);
	root->left->left  = new node(3);
	root->left->right = new node(7);
	root->left->left->right = new node(4);

	root->right = new node(15);
	root->right->left  = new node(13);
	root->right->right = new node(17);
	root->right->right->left = new node(16);

	node* minNode = findMinimum(root);
	node* maxNode = findMaximum(root);

	minNode ? cout << "minVal : " << minNode->data << endl :
	          cout << "minNode doesn't exist" << endl;

	maxNode ? cout << "maxVal : " << maxNode->data << endl :
	          cout << "maxNode doesn't exist" << endl;
	
	return 0;
}


