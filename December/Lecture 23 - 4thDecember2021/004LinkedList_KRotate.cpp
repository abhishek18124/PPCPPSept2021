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


node* kRotate(node* head, int k) {
	if(!head) return head;

	// 1. Form a loop by connecting the tail node with the head node
	node* tail = head;
	int n = 1;
	while(tail->next != NULL) {
		tail = tail->next;
		n++;
	}
	tail->next = head;

	// 2. Get hold of the newTail @ (n-(k%n)-1)th index
	node* newTail = head;
	for(int i=0; i<n-(k%n)-1; i++) {
		newTail = newTail->next;
	}

	// 3. Get hold of the newHead @ (n-(k%n))th index i.e. next to the newTail
	node* newHead = newTail->next;

	// 4. Break the loop
	newTail->next = NULL;

	return newHead;

}

int main() {

	node* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	head = kRotate(head, 7);

	printLinkedList(head);

	return 0;
}