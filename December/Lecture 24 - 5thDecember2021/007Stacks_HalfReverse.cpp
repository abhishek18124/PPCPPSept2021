#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>& s, int x, int p) {
	// base case
	if(p == 0) {
		s.push(x);
		return;
	}

	// recursive case
	int y = s.top(); 
	s.pop();

	// ask your friend to push x at the bottom of the remaining stack
	insertAtBottom(s, x, p-1);

	s.push(y);
}

void print(stack<int> s) {
	while(!s.empty()) {
		cout << s.top() << endl;
		s.pop(); 
	}
	cout << endl;
}

void halfReverse(stack<int>& s, int m) {
	if(m == 0) {
		return;
	}

	// recursive case

	int x = s.top(); 
	s.pop();

	// ask, your friend to reverse the remaining stack
	halfReverse(s, m-1);

	// insert x at the bottom of stack which has been reversed
	// by your friend
	insertAtBottom(s, x, m-1);
}

int main() {
		
	stack<int> s;

	s.push(60);
	s.push(50);
	s.push(40);
	s.push(30);
	s.push(20);
	s.push(10);

	int n = s.size();

	print(s);

	halfReverse(s, n/2);

	print(s);

	return 0;
}