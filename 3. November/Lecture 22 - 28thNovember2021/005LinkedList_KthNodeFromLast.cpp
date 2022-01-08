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

node* kthNodeFromLast(node* head, int k) {
	if(head == NULL) {
		return head;
	}

	node* slow = head;
	node* fast = head;

	while(k-- && fast != NULL) {
		fast = fast->next;
	}

	while(fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;

}


// node* kthNodeFromLast(node* head, int k) {
// 	if(!head) {
// 		return head;
// 	}

// 	node* slow = head;
// 	node* fast = head;

// 	while(k-- && fast) {
// 		fast = fast->next;
// 	}

// 	while(fast) {
// 		slow = slow->next;
// 		fast = fast->next;
// 	}

// 	return slow;

// }


int main() {

	node* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int k = 2;

	node* kthNode = kthNodeFromLast(head, k);

	// if(kthNode) { // or kthNode != NULL
	// 	cout << "kthNodeFromLast : " << kthNode->data << endl;
	// } else {
	// 	cout << "kthNodeFromLast : NULL" << endl;
	// }

	kthNode ?  cout << kthNode->data << endl : cout << "NULL" << endl;


	return 0;
}