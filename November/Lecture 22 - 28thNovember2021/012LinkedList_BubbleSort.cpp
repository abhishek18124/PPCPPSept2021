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

int computeLengthIterative(node* head) {
	int count = 0;
	while(head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

node* bubbleSort(node* head) {

	if(!head || !head->next) {
		return head;
	}

	int n = computeLengthIterative(head);
	int i = 1;

	while(i < n) {
		int j = 0;
		node* cur = head;
		node* prev = NULL;
		node* tmp = NULL;
		while(j < n-i && cur != NULL && cur->next != NULL) {
			tmp = cur->next;
			if(cur->data > tmp->data) {
				// swap cur with tmp
				if(prev != NULL) {
					cur->next = tmp->next;
					tmp->next = cur;
					prev->next = tmp;
					prev = tmp;
				} else {
					cur->next = tmp->next;
					tmp->next = cur;
					head = tmp;
					prev = tmp;
				}
			} else {
				// do not swap
				prev = cur;
				cur = tmp;
			}

			j++;
		}
		i++;
	}

	return head;

}

int main() {

	node* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLinkedList(head);

	head = bubbleSort(head);

	printLinkedList(head);

	return 0;
}