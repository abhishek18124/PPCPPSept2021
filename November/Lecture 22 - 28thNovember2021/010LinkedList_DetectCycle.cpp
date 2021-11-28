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

node* mergeSort(node* head1) {

	// Base Case
	if(head1 == NULL || head1->next == NULL) {
		// LinkedList is already sorted
		return head1;
	}

	// 1. Compute the midPoint

	node* midPoint = getMidPoint(head1);

	// 2. Divide the LinkedList around the midPoint

	node* head2 = midPoint->next;
	midPoint->next = NULL;

	// 3. Recursively mergeSort subLists

	head1 = mergeSort(head1);
	head2 = mergeSort(head2);

	// 4. Merge two sorted LinkedLists

	return merge(head1, head2);

}

bool isCyclePresent(node* head) {
	if(!head) return false;

	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			return true;
		}
	}

	return false;
}

void removeCycle(node* head) {

	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			break;
		}
	}

	node* prev = head;
	while(prev->next != fast) {
		prev = prev->next;
	}

	slow = head;

	while(slow != fast) {
		slow = slow->next;
		fast = fast->next;
		prev = prev->next;
	}

	prev->next = NULL;

}

int main() {

	node* head = new node(10);
	head->next = new node(20);
	head->next->next = new node(30);
	head->next->next->next = new node(40);
	head->next->next->next->next = new node(50);
	head->next->next->next->next->next = new node(60);
	head->next->next->next->next->next->next = new node(70);
	head->next->next->next->next->next->next->next = new node(80);
	head->next->next->next->next->next->next->next->next = head->next->next->next;

	isCyclePresent(head) ? cout << "true" << endl :
						   cout << "false" << endl;
						   
	removeCycle(head);

	isCyclePresent(head) ? cout << "true" << endl :
						   cout << "false" << endl;

	printLinkedList(head);

 	
	return 0;
}