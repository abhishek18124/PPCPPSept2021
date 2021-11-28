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

// node* insertAtHead(node* head, int data) {
// 	// 1. create a new node dynamically with the given data

// 	node* n = new node(data);

// 	// 2. assign to the next field of the newly created node
// 	// the address of the head node which is stored inside 
// 	// the pointer to the head node

// 	n->next = head; // (*n).next = head;

// 	// 3. make the newly created node, the new head of the 
// 	// linked list i.e. assign to the pointer to the head
// 	// node the address of the newly created node

// 	head = n;

// 	return head;
// }

node* getTail(node* tail) {
	while(tail->next != NULL) {
		tail = tail->next;
	}
	return tail;
}

void insertAtTail(node*& head, int data) {

	if(head == NULL) {
		// the linked list is empty
		insertAtHead(head, data);
		return;
	}

	// 1. get access to the pointer to the tail node

	node* tail = getTail(head);

	// 2. create a new node

	node* n = new node(data);

	// 3. assign to the next field of the tail node the
	// address of the newly created node.

	tail->next = n;

}

node* getNode(node* head, int i) {
	int j = 0;
	while(j < i && head != NULL) {
		head = head->next;
		j++;
	}

	return head;
}

void insertAtIndex(node*& head, int data, int i) {

	if(head == NULL || i == 0) {
		insertAtHead(head, data);
		return;
	}

	// 1. get access to the node at index i-1
	node* prev = getNode(head, i-1);

	if(prev == NULL) {
		// the index supplied by the user exceeds the length of the linked list
		insertAtTail(head, data);
		return;
	}

	// 2. create a new node
	node* n = new node(data);

	// 3. assign to the next field of the newly created
	// node the address of the node that comes after the
	// previous node

	n->next =  prev->next;

	// 4. assign to the next field of the previous node
	// the address of the newly created node

	prev->next = n;

}


void printLinkedList(node* head) {
	while(head != NULL) {
		cout << head->data;
		head = head->next;
		if(head != NULL) cout << "->";
	}
	cout << endl;
}


int main() {

	node* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	// head = insertAtHead(head, 50);
	// head = insertAtHead(head, 30);
	// head = insertAtHead(head, 20);
	// head = insertAtHead(head, 10);

	printLinkedList(head);

	insertAtTail(head, 60);

	printLinkedList(head);

	insertAtIndex(head, 40, 3);

	printLinkedList(head);

	return 0;
}