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
	if(!head) {
		return head;
	}

	node* tail = head; // this represents the tail of the final linked list
					   // or the last distinct node that I've seen
	node* cur = head->next;

	while(cur != NULL) {
		if(cur->data != tail->data) {
			// track the current node
			tail->next = cur;
			tail = cur;
			cur = cur->next;
		} else {
			// cur contains duplicate data so skip it
			cur = cur->next;
		}
	}

	tail->next = NULL;

	return head;
}

int main() {

	node* head = NULL;

	insertAtHead(head, 4);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	printLinkedList(head);

	head = deleteDuplicates(head);

	printLinkedList(head);

	return 0;
}