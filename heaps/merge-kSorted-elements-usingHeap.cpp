#include <bits/stdc++.h> 
#include <queue>
using namespace std;

class node {
public:
    int data;
    int row;
    int col;

    node(int val, int i, int j) {
        data = val;
        row = i;
        col = j;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    priority_queue<node*, vector<node*>, compare> minHeap;
    vector<int> ans;

    // Step 1: push first element of each array
    for (int i = 0; i < k; i++) {
        if (!kArrays[i].empty()) {   // safety check
            node* temp = new node(kArrays[i][0], i, 0);
            minHeap.push(temp);
        }
    }

    // Step 2: process heap
    while (!minHeap.empty()) {
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->row;
        int j = temp->col;

        // Step 3: push next element from same row
        if (j + 1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j+1], i, j+1);  // fixed j+1
            minHeap.push(next);
        }
    }

    return ans;
}

int main() {
    int T;
    cin >> T;   // number of test cases
    while (T--) {
        int K;
        cin >> K;  // number of arrays
        vector<vector<int>> kArrays(K);

        for (int i = 0; i < K; i++) {
            int n;
            cin >> n;  // size of current array
            kArrays[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> kArrays[i][j];
            }
        }

        vector<int> result = mergeKSortedArrays(kArrays, K);

        for (int x : result) cout << x << " ";
        cout << endl;
    }
    return 0;
}
