#include<iostream>
#include<stack>

using namespace std;

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