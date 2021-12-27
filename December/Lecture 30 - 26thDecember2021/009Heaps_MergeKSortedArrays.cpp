/*

    Given k sorted arrays, merge them and print the sorted output.

    k = 3
    Input : {
                {1, 3, 5, 7}, 
                {2, 4, 6, 8}, 
                {0, 9, 10, 11}
            }

    Output: 0 1 2 3 4 5 6 7 8 9 10 11 

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

    vector<vector<int>> arr = {{1, 3, 5, 7}, 
                             {2, 4, 6, 8}, 
                             {0, 9, 10, 11}};

    int k = arr.size();

    priority_queue<
                    vector<int>, 
                    vector<vector<int>>, 
                    greater<vector<int>>
                  > minHeap;

    for(int arr_idx=0; arr_idx<k; arr_idx++) {
        int val_idx = 0;
        int val = arr[arr_idx][val_idx];
        minHeap.push({val, arr_idx, val_idx});
    }

    vector<int> result;
    while(!minHeap.empty()) {
        vector<int> v = minHeap.top(); // [val, arr_idx, val_idx]
        minHeap.pop();

        int val = v[0];
        int arr_idx = v[1];
        int val_idx = v[2];

        result.push_back(val);

        int next_val_idx = val_idx+1;
        if(next_val_idx < arr[arr_idx].size()) {
            int next_val = arr[arr_idx][next_val_idx];
            minHeap.push({next_val, arr_idx, next_val_idx});
        }

    }

    for(auto x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}