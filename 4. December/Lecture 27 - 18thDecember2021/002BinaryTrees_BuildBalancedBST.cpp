/*

	Given a inOrder traversal of a BST, design an algorithm to build a balanced BST.

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

node* buildBBST(int* in, int s, int e) {

	// base case
	if(s > e) {
		// build an empty tree
		return NULL;
	}

	// recursive case

	int m = s + (e-s)/2;
	node* root = new node(in[m]);

	// build the leftSubtree using in[s:m-1] -- ask your friend
	root->left = buildBBST(in, s, m-1);

	// build the rightSubtree using in[m+1:e] -- ask your friend
	root->right = buildBBST(in, m+1, e);

	return root;

}

int main() {

	int in[] = {3, 5, 7, 10, 13, 15, 17};
	int n = sizeof(in) / sizeof(int);

	node* root = buildBBST(in, 0, n-1);

	levelOrder(root);

	cout << endl;
	
	return 0;
}


