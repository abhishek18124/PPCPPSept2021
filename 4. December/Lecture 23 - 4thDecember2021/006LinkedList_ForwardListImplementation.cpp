#include<iostream>

using namespace std;

template <typename T>
class node {
public:

	T data;
	node<T>* next;

	node(T data) {
		this->data = data;
		this->next = NULL;
	}

};

template <typename T>
class forward_list {
	node<T>* head;
	int count;

	public :

		forward_list() {
			this->head = NULL;
			this->count = 0;
		}

		void push_front(T data) {
			node<T>* n = new node<T>(data);
			n->next = head;
			head = n;
			count++;
		}

		void pop_front() {
			if(!head) return;
			node<T>* tmp = head;
			head = head->next;
			delete tmp;
			count--;
		}

		int size() {
			return count;
		}

		T front() {
			return head->data;
		}

		bool empty() {
			return head == NULL;
		}

		void traverse() {
			node<T>* tmp = head;
			while(tmp != NULL) {
				cout << tmp->data;
				tmp = tmp->next;
				if(tmp != NULL) cout << "->";
			}
			cout << endl;
		}
};

int main() {

	forward_list<string> l;

	l.push_front("aa");
	l.push_front("ab");
	l.push_front("ac");
	l.push_front("ad");
	l.push_front("ae");

	l.traverse();

	l.pop_front();

	l.traverse();

	cout << "size = " << l.size() << endl;

	l.empty() ? cout << "true" << endl : cout << "false" << endl;

	l.pop_front();
	l.pop_front();
	l.pop_front();
	l.pop_front();


	l.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}