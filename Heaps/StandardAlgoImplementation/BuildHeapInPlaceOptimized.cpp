/*
    User:- sanyam

    We will do the same conversion of array to Heap in O(N)
    Proof is same as before
    But here we will apply heapify down for nodes from index N/2 to 1

*/
#include <bits/stdc++.h>
using namespace std;

void buildHeapOptimised(vector<int> &v) {
    int idx = (v.size() - 1) / 2;
    int n = v.size();

    for (int i = idx; i >= 0; i--) {
        int id = i;
        while (id < n) {
            int left = 2 * id + 1;
            int right = 2 * id + 2;
            int minid = id;

            if (left < n && v[left] > v[minid]) {
                minid = left;
            }
            if (right < n && v[right] > v[minid]) {
                minid = right;
            }
            if (minid == id) break;
            swap(v[minid], v[id]);
            id = minid;
        }
    }
}

int main() {
    vector<int> v = {10, 20, 5, 6, 1, 8, 9, 4};
    buildHeapOptimised(v);

    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}