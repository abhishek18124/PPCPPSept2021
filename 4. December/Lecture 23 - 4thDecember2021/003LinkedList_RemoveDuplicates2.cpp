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


node* deleteDuplicates(node* head) {
	// base case
	if(!head || !head->next) {
		return head;
	}

	// recursive case
	if(head->data != head->next->data) {
		// head node is a distinct node and will be part of the final answer
		node* headFromMyFriend = deleteDuplicates(head->next);
		head->next = headFromMyFriend;
		return head;
	} else {
		// head node is a duplicatte node therfore it is our responsibility
		// to skip the entire sublist of nodes where data matches the data
		// of the head node
		while(head->next && head->data == head->next->data) {
			head = head->next;
		}
		node* headFromMyFriend = deleteDuplicates(head->next);
		return headFromMyFriend;
	}
}

int main() {

	node* head = NULL;

	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 3);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertAtHead(head, 1);
	insertAtHead(head, 1);
	insertAtHead(head, 0);

	printLinkedList(head);

	head = deleteDuplicates(head);

	printLinkedList(head);

	return 0;
}