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

int main() {
		
	stack<int> s;

	s.push(50);
	s.push(40);
	s.push(30);
	s.push(20);
	s.push(10);

	int x = 60;

	print(s);

	insertAtBottom(s, x);

	print(s);

	return 0;
}