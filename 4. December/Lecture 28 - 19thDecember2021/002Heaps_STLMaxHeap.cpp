/*

	STL implementation of the heap/priority_queue data structure.


*/

#include<iostream>
#include<queue>

using namespace std;

int main() {

	priority_queue<int> maxHeap;

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