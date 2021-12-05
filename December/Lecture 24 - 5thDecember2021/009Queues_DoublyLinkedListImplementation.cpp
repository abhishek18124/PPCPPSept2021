#include<iostream>
#include<list>

using namespace std;

template <typename T>
class queue {
	list<T> l;
public:
	void push(T data) {
		l.push_back(data);
	}

	void pop() {
		l.pop_front();
	}

	int size() {
		return l.size();
	}	

	T front() {
		return l.front();
	}

	T back() {
		return l.back();
	}

	bool empty() {
		return l.empty();
	}
};

void print(queue<int> q) {
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main() {

	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl;

	print(q);

	q.pop();

	cout << "front : " << q.front() << endl;

	q.pop();
	q.pop();

	q.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}