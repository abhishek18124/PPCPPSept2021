/*

Implementation of the TRIE data structure to store strings.

Motivation :

Given an array of N strings, and an array of Q queries, check for each query if it
it present in the array or not.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

class node {

	public :

		char data;
		bool terminal;
		unordered_map<char, node*> childMap;

		node(int data) {
			this->data = data;
			this->terminal = false;
		}

};

class trie {
	node* root;

	public :

		trie() {
			root = new node('\0');
		}

		void insert(string str) {
			node* temp = root;
			for(char ch : str) {
				// check if the current node has a child node 
				// with the value ch
				if(temp->childMap.find(ch) == temp->childMap.end()) {
					// temp node doesn't have a child node with data as ch
					node* n = new node(ch);
					temp->childMap[ch] = n;
					temp = temp->childMap[ch];
				} else {
					// temp node has a child node with data as ch
					temp = temp->childMap[ch];
				}
			}
			temp->terminal = true;
		}

		bool search(string str) {
			node* temp = root;
			for(char ch : str) {
				if(temp->childMap.find(ch) == temp->childMap.end()) {
					return false;
				}
				temp = temp->childMap[ch];
			}
			return temp->terminal;
		}
};

int main() {

	string words[] = {"code", "coder", "coding",
                      "news", "newspaper", "newsdesk",
                      "cruze", "cruise"};

    trie t;
    for(string word : words) {
    	t.insert(word);
    }

    string queries[] = {"coder", "codes", "news", "new", "cruise"};

    for(string query : queries) {
    	t.search(query) ? cout << query << " :  present" << endl :
    	                  cout << query << " : not present" << endl; 
    }

	return 0;
}