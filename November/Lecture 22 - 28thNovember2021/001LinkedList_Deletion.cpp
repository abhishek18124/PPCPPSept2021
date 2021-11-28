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

void deleteFromHead(node*& head) {

	if(head == NULL) {
		// linked list is empty
		return;
	}

	node* temp = head;

	// 2. assign to the head pointer the address of the node
	// that comes after the head node

	head = head->next;

	delete temp;
}

void deleteFromTail(node*& head) {

	if(head == NULL) {
		return;
	}

	if(head->next == NULL) {
		deleteFromHead(head);
		return;
	}

	node* prev = NULL;
	node* tail = head;

	while(tail->next != NULL) {
		prev = tail;
		tail = tail->next;
	}

	prev->next = NULL;
	delete tail;

}

node* getNode(node* head, int i) {
	int j = 0;
	while(j < i && head != NULL) {
		head = head->next;
		j++;
	}

	return head;
}


void deleteFromIndex(node*& head, int i) {

	if(head == NULL) {
		return;
	}

	if(i == 0) {
		deleteFromHead(head);
		return;
	}

	node* cur = getNode(head, i);
	if(cur == NULL) {
		// the index supplied by the user exceeds the length of the
		// linked list
		return;
	}

	node* prev = getNode(head, i-1);
	prev->next = cur->next;
	delete cur;
}

int main() {

	node* head = NULL;

	insertAtHead(head, 60);
	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	deleteFromHead(head);

	printLinkedList(head);

	deleteFromTail(head);

	printLinkedList(head);

	deleteFromIndex(head, 2);

	printLinkedList(head);

	deleteFromIndex(head, 1);

	printLinkedList(head);

	return 0;
}