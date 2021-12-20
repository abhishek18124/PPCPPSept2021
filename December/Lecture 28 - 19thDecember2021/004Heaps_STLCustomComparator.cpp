/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class Comparator {
public:
	bool operator()(int a, int b) { // return true when swap is needed
		// return a < b; // for MaxHeap
		return a > b; // for MinHeap
	}

};

int main() {

	priority_queue<int, vector<int>, Comparator> minHeap;

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