#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class node {
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;  // min-heap based on data
    }
};

pair<int,int> kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;

    // Min-heap of nodes
    priority_queue<node*, vector<node*>, compare> minHeap;

    // Step 1: Insert first element of each list into heap
    for (int i = 0; i < k; i++) {
        int element = a[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini, end = maxi;

    // Step 2: Process heap until one list is exhausted
    while (!minHeap.empty()) {
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        // update answer range
        if ((maxi - mini) < (end - start)) {
            start = mini;
            end = maxi;
        }

        // push next element from the same row (list)
        if (temp->col + 1 < n) {
            int nextElement = a[temp->row][temp->col + 1];
            maxi = max(maxi, nextElement);
            minHeap.push(new node(nextElement, temp->row, temp->col + 1));
        } else {
            // if one list is finished, stop
            break;
        }
    }

    return {start, end};
}

int main() {
    vector<vector<int>> arr = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    int k = arr.size();      // number of lists
    int n = arr[0].size();   // assuming all lists have equal size here

    pair<int,int> ans = kSorted(arr, k, n);
    cout << "Smallest Range: [" << ans.first << ", " << ans.second << "]\n";
    cout << "Length of Range: " << ans.second - ans.first + 1 << "\n";

    return 0;
}
