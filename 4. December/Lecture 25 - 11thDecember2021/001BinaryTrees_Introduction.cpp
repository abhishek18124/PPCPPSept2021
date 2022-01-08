#include<iostream>

using namespace std;

template <typename T>
class node {

public:
	T data;
	node<T>* left;
	node<T>* right;

	node(T data) {
		this->data = data;
		this->left = this->right = NULL;
	}

};

template <typename T>
void preOrder(node<T>* root) {
	if(root == NULL) {
		// root represents an empty tree
		cout << -1 << " ";
		return;
	}

	// recursive case

	// 1. process/explore the root node
	cout << root->data << " ";

	//2. do the preOrder traversal of the left subtree -- ask your friend
	preOrder(root->left);

	//3. do the preOrder traversal of the right subtree -- ask your friend
	preOrder(root->right);	
}

template <typename T>
void inOrder(node<T>* root) {
	if(root == NULL) {
		// root represents an empty tree
		cout << -1 << " ";
		return;
	}

	// recursive case

	//1. do the inOrder traversal of the left subtree -- ask your friend
	inOrder(root->left);

	// 2. process/explore the root node
	cout << root->data << " ";

	//3. do the inOrder traversal of the right subtree -- ask your friend
	inOrder(root->right);	
}

template <typename T>
void postOrder(node<T>* root) {
	if(root == NULL) {
		// root represents an empty tree
		cout << -1 << " ";
		return;
	}

	// recursive case

	//1. do the postOrder traversal of the left subtree -- ask your friend
	postOrder(root->left);

	//2. do the postOrder traversal of the right subtree -- ask your friend
	postOrder(root->right);	

	//3. process/explore the root node
	cout << root->data << " ";

}

int main() {

	node<int>* root = NULL; // initially, tree is empty

	root = new node<int>(10);
	root->left = new node<int>(20);
	root->right= new node<int>(30);
	root->left->left = new node<int>(40);
	root->left->right = new node<int>(50);
	root->right->right = new node<int>(60);
	root->left->right->left = new node<int>(70);
	
	preOrder(root); cout << endl;
	inOrder(root); cout << endl;
	postOrder(root); cout << endl;

	return 0;
}








