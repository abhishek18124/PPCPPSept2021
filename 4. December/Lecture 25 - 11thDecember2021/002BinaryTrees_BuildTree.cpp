/*

Design a recursive algorithm to build a binary tree given its pre-order traversal.

eg: preOrder : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1

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

void inorder(node* root) {
	if(root == NULL) {
		// root represents an empty tree
		cout << "-1 ";
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(node* root) {
	if(root == NULL) {
		// root represents an empty tree
		cout << "-1 ";
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
	
}

node* buildTree() {

	// 1. read the first value from the given preOrder traversal
	int data;
	cin >> data;

	if(data == -1) {
		// you are trying to build an empty tree
		return NULL;
	}

	// 2. create a root node using the data you've read
	node* root = new node(data);

	// 3. build the leftSubtree by reading its preOrder traversal
	root->left = buildTree();

	//4. build the rightSubtree by reading its preOrder traversal
	root->right = buildTree();

}

int main() {

	node* root = NULL;
	
	root = buildTree();

	preorder(root); cout << endl;
	inorder(root); cout << endl;
	postorder(root); cout << endl;

	return 0;
}


