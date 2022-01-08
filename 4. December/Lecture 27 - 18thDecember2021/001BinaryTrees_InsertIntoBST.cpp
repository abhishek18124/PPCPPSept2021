/*

	Design an algorithm to perform insert operation in a BST.

*/

#include<iostream>
#include<queue>

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


void inOrder(node* root) {
	if(root == NULL) {
		return;
	}

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		node* front = q.front(); q.pop();
		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->data << " ";
			if(front->left) q.push(front->left);
			if(front->right)q.push(front->right);
		}
	}
}

node* insertIntoBST(node* root, int key) {

	// base case

	if(root == NULL) {
		// insert key in an empty tree
		node* root = new node(key);
		return root;
	}

	// recursive case

	if(key < root->data) {
		// insert the key in the leftSubtree which is also a BST -- ask your friend	
		root->left = insertIntoBST(root->left, key);
	} else {
		// insert the key in the rightSubtree which is also a BST -- ask your friend
		root->right = insertIntoBST(root->right, key);
	}

	return root;

}

void rangeQuery(node* root, int s, int e) {
	if(root == NULL) {
		return;
	}

	rangeQuery(root->left, s, e);
	if(root->data >= s && root->data <= e) {
		cout << root->data << " ";
	}
	rangeQuery(root->right, s, e);
}


int main() {

	node* root = NULL;

	root = insertIntoBST(root, 10);
	root = insertIntoBST(root, 5);
	root = insertIntoBST(root, 3);
	root = insertIntoBST(root, 7);
	root = insertIntoBST(root, 15);
	root = insertIntoBST(root, 13);
	root = insertIntoBST(root, 17);

	levelOrder(root);

	cout << endl;

	inOrder(root);

	cout << endl;

	rangeQuery(root, 5, 15);

	cout << endl;

	return 0;
}
