/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class MaxHeap {

	vector<int> v;

	void heapify(int i) {
		int max_idx = i; // assume node at the ith index is the maximum
		int left_idx= 2*i;

		if(left_idx < v.size() && v[left_idx] > v[max_idx]) {
			max_idx = left_idx;
		}

		int right_idx = 2*i + 1;
		if(right_idx < v.size() && v[right_idx] > v[max_idx]) {
			max_idx = right_idx;
		}

		if(max_idx != i) {
			swap(v[max_idx], v[i]);
			heapify(max_idx);
		}

	}

	public :

		MaxHeap() {
			v.push_back(0); // to reserve the 0th index
		}

		void push(int data) {
			v.push_back(data); // this may lead to violation of the heap property
			int childIndex = v.size() - 1;
			int parentIndex = childIndex / 2;
			while(childIndex > 1 && v[childIndex] > v[parentIndex]) {
				swap(v[childIndex], v[parentIndex]);
				childIndex = parentIndex;
				parentIndex = childIndex / 2;
			}
		}

		void pop() {
			swap(v[1], v[v.size()-1]);
			v.pop_back();
			heapify(1);
		}

		int top() {
			return v[1];
		}

		int size() {
			return v.size() - 1;
		}

		bool empty() {
			return v.size() == 1;
		}


};

int main() {

	MaxHeap maxHeap;

	for(int data=0; data<=10; data++) {
		maxHeap.push(data);
	}

	cout << "size : " << maxHeap.size() << endl;

	while(!maxHeap.empty()) {
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}

	cout << endl;

	
	cout << "size : " << maxHeap.size() << endl;

	return 0;
}





