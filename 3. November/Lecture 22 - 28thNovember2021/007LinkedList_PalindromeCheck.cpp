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

node* reverseIterative(node* head) {

	node* cur = head;
	node* prev= NULL;
	
	while(cur != NULL) {
		node* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
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


bool isPalindrome(node* head1) {
	if(!head1 || !head1->next) {
		return true;
	}

	node* midPoint = getMidPoint(head1);
	node* head2 = reverseIterative(midPoint->next);
	midPoint->next = NULL;

	while(head2 != NULL) {
		if(head1->data != head2->data) {
			return false;
		}
		head1 = head1->next;
		head2 = head2->next;
	}

	return true;

}

int main() {

	node* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	isPalindrome(head) ? cout << "true" << endl :
	                     cout << "false" << endl;

	return 0;
}