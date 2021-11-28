#include<iostream>

using namespace std;

class node {
public:

	int data;
	node* next;

	node(int data) {
		this->data = data;
		this->next = NULL;
	}

};

void insertAtHead(node*& head, int data) {
	// 1. create a new node dynamically with the given data

	node* n = new node(data);

	// 2. assign to the next field of the newly created node
	// the address of the head node which is stored inside 
	// the pointer to the head node

	n->next = head; // (*n).next = head;

	// 3. make the newly created node, the new head of the 
	// linked list i.e. assign to the pointer to the head
	// node the address of the newly created node

	head = n;
}


void printLinkedList(node* head) {
	while(head != NULL) {
		cout << head->data;
		head = head->next;
		if(head != NULL) cout << "->";
	}
	cout << endl;
}

bool isPresentIterative(node* head, int t) {
	while(head != NULL) {
		if(head->data == t) {
			// you've found the target in the given linked list
			return true;
		}
		head = head->next;
	}

	// target is not present inside the given linked list
	return false;

}

bool isPresentRecursive(node* head, int t) {

	// base case
	if(head == NULL) {
		// you are trying to search for the target in an empty linked list
		return false;
	}

	// recursive case

	if(head->data == t) {
		// you've found the target at the head node
		return true;
	}

	// ask your friend to search for the target in the linked list
	// that starts from the node that comes after the head node

	return isPresentRecursive(head->next, t);
}



int main() {

	node* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int t = 100;

	isPresentIterative(head, t) ? cout << "true" << endl :
							      cout << "false" << endl;


	isPresentRecursive(head, t) ? cout << "true" << endl :
							      cout << "false" << endl;

	return 0;
}