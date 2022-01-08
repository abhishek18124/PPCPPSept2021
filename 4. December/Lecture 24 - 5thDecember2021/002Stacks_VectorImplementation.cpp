#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class stack {
	vector<T> A;

	public :

		void push(T data) {
			A.push_back(data);
		}

		void pop() {
			if(!empty()) {
				A.pop_back();
			}
		}

		int size() {
			return A.size();
		}

		bool empty() {
			return A.empty();
		}

		T top() {
			return A.back(); // or A[A.size()-1]
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