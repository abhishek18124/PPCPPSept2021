/*

Given an infinite stream of non-negative integers, design an algorithm to output the 
top-K integers every time you encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<iostream>
#include<queue>

using namespace std;

void print(priority_queue<int, vector<int>, greater<int>> minHeap) {
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {

    priority_queue<int, vector<int>, greater<int>> minHeap;

    int k; 
    cin >> k;

    int x; // to read data from the stream

    // push the first k element from the stream directly into the minHeap

    for(int i=0; i<k; i++) {
        cin >> x;
        minHeap.push(x);
    }

     while(true) {
        cin >> x;
        if(x == -1) {
            // print the top-k elements i.e. contents of the minHeap
            print(minHeap);
        } else {
            // check if x is greater than the minimum of the current top-K i.e. root of minHeap
            if(x > minHeap.top()) {
                minHeap.pop(); // delete the minimum element
                minHeap.push(x); // insert the current element
            }
        }

     }

    return 0;

}