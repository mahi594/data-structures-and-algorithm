#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  
    void heapify(vector<int> &arr, int n, int i) {
        int largest = i;
        int child1 = 2*i + 1;
        int child2 = 2*i + 2;
        
        if(child1 < n && arr[largest] < arr[child1]) {
            largest = child1;
        }
        if(child2 < n && arr[largest] < arr[child2]) {
            largest = child2;
        }
        
        if(largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
  
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // 1: merge two arrays
        vector<int> ans;
        for(int i = 0; i < n; i++) ans.push_back(a[i]);
        for(int i = 0; i < m; i++) ans.push_back(b[i]);
        
        int k = ans.size();
        
        // 2: build heap using merged array
        for(int i = k/2 - 1; i >= 0; i--) {
            heapify(ans, k, i);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    // Example heaps
    vector<int> a = {10, 5, 6, 2};   // max heap
    vector<int> b = {12, 7, 9};      // max heap

    int n = a.size();
    int m = b.size();

    vector<int> mergedHeap = sol.mergeHeaps(a, b, n, m);

    cout << "Merged Max Heap: ";
    for(int val : mergedHeap) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
