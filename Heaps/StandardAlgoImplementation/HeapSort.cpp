/*
    user - sanyam
    Steps
    i. Build MaxHeap from array in O(N)
    ii. Pop the elements one by one from 1 to n-1(replace with last element)
    iii. Decrease the size by 1 and do it for n-1 elements.
    iv. So atlast we will get the Sorted array.

    It is inplace and O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int minid = i;
    if (left < n && arr[left] > arr[minid]) {
        minid = left;
    }
    if (right < n && arr[right] > arr[minid]) {
        minid = right;
    }
    if (minid != i) {
        swap(arr[i], arr[minid]);
        heapify(arr, minid, n);
    }
}

void buildHeap(int arr[], int n) {
    int id = (n - 1) / 2;
    for (int i = id; i >= 0; i--) {
        heapify(arr, i, n);
    }
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    heapSort(arr, n);
    cout << "Sorted Array is\n";
    for (int x : arr) cout << x << " ";
}