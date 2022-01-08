#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>& s, int x) {
	// base case
	if(s.empty()) {
		s.push(x);
		return;
	}

	// recursive case
	int y = s.top(); 
	s.pop();

	// ask your friend to push x at the bottom of the remaining stack
	insertAtBottom(s, x);

	s.push(y);
}

void print(stack<int> s) {
	while(!s.empty()) {
		cout << s.top() << endl;
		s.pop(); 
	}
	cout << endl;
}

void reverse(stack<int>& s) {
	if(s.empty()) {
		return;
	}

	// recursive case

	int x = s.top(); 
	s.pop();

	// ask, your friend to reverse the remaining stack
	reverse(s);

	// insert x at the bottom of stack which has been reversed
	// by your friend
	insertAtBottom(s, x);
}

int main() {
		
	stack<int> s;

	s.push(50);
	s.push(40);
	s.push(30);
	s.push(20);
	s.push(10);

	print(s);

	reverse(s);

	print(s);

	return 0;
}