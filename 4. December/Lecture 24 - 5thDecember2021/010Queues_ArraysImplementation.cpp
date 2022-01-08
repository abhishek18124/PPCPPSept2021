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
		this->n = n;
		A = new T[n+1];
		f = r = 0;
		count = 0;
	}

	void push(T data) {
		if(r+1 == n+1) {
			return;
		}

		r = r + 1;
		A[r] = data;
		count++;
	}

	void pop() {
		if(f == r) {
			return;
		}
		f = f + 1;
		count--;
	}

	int size() {
		return count;
	}

	bool empty() {
		return f == r;
	}

	T front() {
		return A[f+1];
	}

};

int main() {

	queue<int> q(5);

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	q.empty() ? cout << "true" << endl : cout << "false" << endl;


	return 0;
}