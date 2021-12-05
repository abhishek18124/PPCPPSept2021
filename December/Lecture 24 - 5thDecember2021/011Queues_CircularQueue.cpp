#include<iostream>

using namespace std;

template <typename T>
class queue {

	T* A;
	int count;
	int f;
	int r;
	int n;

public:

	queue(int n) {
		this->n = n+1;
		A = new T[n+1];
		f = r = 0;
		count = 0;
	}

	void push(T data) {
		if((r+1)%n == f) {
			return;
		}

		r = (r+1)%n;
		A[r] = data;
		count++;
	}

	void pop() {
		if(f == r) {
			return;
		}
		f = (f+1)%n;
		count--;
	}

	int size() {
		return count;
	}

	bool empty() {
		return f == r;
	}

	T front() {
		return A[(f+1)%n];
	}

};

int main() {

	queue<int> q(3);

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.empty() ? cout << "true" << endl : cout << "false" << endl;

	q.push(40);

	cout << "size : " << q.size() << endl;

	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << endl;


	
	return 0;
}