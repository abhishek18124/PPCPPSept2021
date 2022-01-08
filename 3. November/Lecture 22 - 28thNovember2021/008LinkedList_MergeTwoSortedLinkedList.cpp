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

node* getMidPoint(node* head) {
	if(head == NULL) {
		return head;
	}

	node* slow = head;
	node* fast = head->next;

	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}



node* merge(node* head1, node* head2) {

	// base case
	if(head1 == NULL) {
		return head2;
	}

	if(head2 == NULL) {
		return head1;
	}

	// recursive case
	node* head = NULL;

	if(head1->data < head2->data) {
		// the node pointed by head1 will be the head of the merged linked list
		head = head1;
		head->next = merge(head1->next, head2);
	} else {
		// the node pointed by head2 will be the head of the merged linked list
		head = head2;
		head->next = merge(head1, head2->next);
	}

	return head;

}

int main() {

	node* head1 = NULL;

	insertAtHead(head1, 50);
	insertAtHead(head1, 30);
	insertAtHead(head1, 10);

	printLinkedList(head1);

	node* head2 = NULL;

	insertAtHead(head2, 60);
	insertAtHead(head2, 40);
	insertAtHead(head2, 20);

	printLinkedList(head2);

	node* head = merge(head1, head2);

	printLinkedList(head);

	return 0;
}