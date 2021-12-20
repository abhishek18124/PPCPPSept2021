/*

	STL implementation of the min_heap data structure.


*/

#include<iostream>
#include<queue>

using namespace std;

int main() {

	priority_queue<int, vector<int>, greater<int>> minHeap;

	for(int data=10; data>=0; data--) {
		minHeap.push(data);
	}

	cout << "size : " << minHeap.size() << endl;

	while(!minHeap.empty()) {
		cout << minHeap.top() << " ";
		minHeap.pop();
	}

	cout << endl;

	cout << "size : " << minHeap.size() << endl;

	return 0;
}