/*

given the pre-order traversal of a binary tree, output its level-order traversal.

Example 
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: 10 20 30 40 50 60 70
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

void levelOrder(node* root) {

	queue<node*> q;
	q.push(root);

	while(!q.empty()) {
		node* front = q.front();
		q.pop();

		cout << front->data << " ";
		if(front->left) {
			q.push(front->left);
		}

		if(front->right) {
			q.push(front->right);
		}

	}

	cout << endl;



}

void levelOrderFormatted(node* root) {

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		node* front = q.front();
		q.pop();

		if(!front) {
			// front of the queue contains NULL
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			// front of the queue is a node, therefore process it
			cout << front->data << " ";
			if(front->left) {
				q.push(front->left);
			}

			if(front->right) {
				q.push(front->right);
			}
		}

	}

	cout << endl;



}

int main() {

	node* root = NULL;
	root = buildTree();

	levelOrder(root); cout << endl;
	levelOrderFormatted(root);

	return 0;
}

