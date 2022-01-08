#include<iostream>

using namespace std;

template <typename T>
class stack {
	T* A;
	int top;
	int n;

	public :
		stack(int n) {
			this->A = new T[n];
			this->top = -1;
			this->n = n;
		}

		void push(T data) {
			if(top == n-1) {
				// stack is full
				return;
			}
			top++;
			A[top] = data;
		}

		void pop() {
			if(top == -1) {
				// stack is empty
				return;
			}
			top--;
		}

		int size() {
			return top+1;
		}

		bool empty() {
			return top==-1;
		}

		T peak() {
			return A[top];
		}
};

int main() {

	stack<char> s(5);

	s.push('a');
	s.push('b');
	s.push('c');

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.peak() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.peak() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.peak() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "isEmpty : " << s.empty() << endl;

	return 0;
}