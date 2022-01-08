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

template <typename T>
class stack {
	forward_list<T> A;

	public :

		void push(T data) {
			A.push_front(data);
		}

		void pop() {
			if(!empty()) {
				A.pop_front();
			}
		}

		int size() {
			return A.size();
		}

		bool empty() {
			return A.empty();
		}

		T top() {
			return A.front();
		}
};

int main() {

	stack<char> s;

	s.push('a');
	s.push('b');
	s.push('c');

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "isEmpty : " << s.empty() << endl;

	return 0;
}