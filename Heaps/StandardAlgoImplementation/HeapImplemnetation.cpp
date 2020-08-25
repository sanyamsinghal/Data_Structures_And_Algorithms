#include <bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> arr;
    bool minHeap;

    bool compare(int a, int b) {
        if (minHeap)
            return a < b;
        else
            return a > b;
    }

   public:
    Heap(int default_size, bool type = true) {
        arr.reserve(default_size);
        arr.push_back(-1);
        minHeap = type;
    }

    void heapify(int id) {
        while (id > 1) {
            int parent = id / 2;
            if (compare(arr[id], arr[parent])) {
                swap(arr[id], arr[parent]);
                id = parent;
            } else {
                break;
            }
        }
    }

    void push(int element) {
        arr.push_back(element);
        heapify(arr.size() - 1);
        return;
    }

    void heapify_down(int id) {
        int n = arr.size();
        int left = 2 * id;
        int right = 2 * id + 1;
        int minidx = id;
        if (left < n && compare(arr[left], arr[minidx])) {
            minidx = left;
        }

        if (right < n && compare(arr[right], arr[minidx])) {
            minidx = right;
        }
        if (minidx != id) {
            swap(arr[minidx], arr[id]);
            heapify(minidx);
        }
    }

    int pop() {
        int pop_ele = arr[1];
        arr[1] = arr.back();
        arr.pop_back();

        heapify_down(1);

        return pop_ele;
    }

    void print(int i) {
        if (i >= arr.size()) return;
        cout << arr[i] << " ";
        print(2 * i);
        print(2 * i + 1);
    }

    bool empty() { return arr.size() == 1; }
};

int main() {
    Heap heap(10, true);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int data;
        cin >> data;
        heap.push(data);
    }

    heap.print(1);
    cout << endl;

    while (!heap.empty()) {
        cout << heap.pop() << " ";
    }

    return 0;
}