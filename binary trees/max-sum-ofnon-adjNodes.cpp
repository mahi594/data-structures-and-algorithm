#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

// Binary Tree Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    // Returns a pair: {sum including current node, sum excluding current node}
    pair<int,int> solve(Node* root) {
        // Base case
        if (root == NULL) {
            return {0, 0};
        }
        
        // Recursively solve for left and right subtrees
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        
        // Including current node: node's value + sum excluding children
        res.first = root->data + left.second + right.second;
        
        // Excluding current node: max of including/excluding children
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
    }
    
    int getMaxSum(Node *root) {
        pair<int,int> ans = solve(root);
        // Max of including or excluding root
        return max(ans.first, ans.second);
    }
};

// Helper function to build binary tree from level order (-1 means NULL)
Node* buildTree(const vector<int> &arr) {
    if (arr.empty() || arr[0] == -1) return NULL;
    
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();
        
        // Left child
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        
        // Right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    // Example: level order input for the tree
    // Tree: 
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   1   4   5
    vector<int> arr = {1, 2, 3, 1, 4, -1, 5};
    Node* root = buildTree(arr);
    
    Solution obj;
    cout << "Maximum sum of non-adjacent nodes: " << obj.getMaxSum(root) << endl;
    
    return 0;
}
