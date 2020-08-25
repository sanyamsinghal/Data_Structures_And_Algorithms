/*
    User:- sanyam
    To build a heap from given array into heap in O(NlogN)

    - Here we will iterate from o to n-1 and check if this index is following the property of heap
    - For checking we will do heapify-up process.

    Time Complexity Proof :- 
    1. Do it making using AGP Series.(Based on the number of operators for every height nodes 
    like for 2^(h-1) it is (h-1).
    2. last level node = N/2 (nearly)
    so for them it is O(N/2 * log(N)) => Hence proved
*/
#include <bits/stdc++.h>
using namespace std;

void buildMaxHeap(vector<int> &arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int idx = i;
        int parent = (i - 1) / 2;

        while (idx > 0 && arr[idx] > arr[parent]) {
            swap(arr[idx], arr[parent]);
            idx = parent;
            parent = (idx - 1) / 2;
        }
    }
}

int main() {
    vector<int> arr = {10, 20, 5, 6, 1, 8, 9, 4};  // buildMaxHeap
    buildMaxHeap(arr);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
