/*

	Given a BST, design an algorithm transform it into a sorted linked list in-place.

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

class Pair {
public:
	node* head;
	node* tail;
};

Pair transform(node* root) {

	Pair p;

	// base case

	if(root == NULL) {
		p.head = p.tail = NULL;
		return p;
	}

	// recursive case

	// transform the leftSubtree into a sorted linkedList -- ask your friend
	Pair pL = transform(root->left);

	if(pL.head) {
		pL.tail->right = root;
		p.head = pL.head;
	} else {
		p.head = root;
	}

	// transform the rightSubtree into a sorted linkedList -- ask your friend
	Pair pR = transform(root->right);

	if(pR.head) {
		root->right = pR.head;
		p.tail = pR.tail;
	} else {
		p.tail = root;
	}

	return p;
}

void printLinkedList(node* head) {
	while(head) {
		cout << head->data;
		head = head->right;
		if(head) cout << "->";
	}
	cout << endl;
}

int main() {

	node* root = new node(10);
	
	root->left = new node(5);
	root->left->left  = new node(3);
	root->left->right = new node(7);

	root->right = new node(15);
	root->right->left  = new node(13);
	root->right->right = new node(17);

	Pair p = transform(root);

	printLinkedList(p.head);

	return 0;
}