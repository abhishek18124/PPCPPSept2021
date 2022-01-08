/*

	given the pre-order traversal of a binary tree, output its vertical order traversal.

	Example 
		Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
		Output: 40
		        20 70
		        10 50
		        30
		        60
*/

#include<iostream>
#include<map>
#include<vector>

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

void verticalOrder(node* root, map<int, vector<int>>& m, int d) {
	// base case
	if(!root) {
		return;
	}

	// recusive case

	m[d].push_back(root->data);
	verticalOrder(root->left, m, d-1);
	verticalOrder(root->right, m, d+1);
}

int main() {

	node* root = NULL;
	root = buildTree();

	map<int, vector<int>> m;
	verticalOrder(root, m, 0);

	for(auto p : m) {
		cout << p.first << " ";
		for(auto x : p.second) {
			cout << x << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}

