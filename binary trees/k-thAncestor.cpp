#include <bits/stdc++.h>
using namespace std;

// Structure of a node of the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Helper function to find kth ancestor
    Node* solve(Node* root, int &k, int node, int &ans) {
        if (root == NULL) return NULL;
        
        // If current node is the target node
        if (root->data == node) return root;
        
        // Search in left and right subtrees
        Node* leftAns = solve(root->left, k, node, ans);
        Node* rightAns = solve(root->right, k, node, ans);
        
        // If the node was found in either subtree
        if (leftAns != NULL || rightAns != NULL) {
            k--; // Move one level up in the ancestor chain
            
            // If k becomes 0, current node is the kth ancestor
            if (k == 0) {
                ans = root->data;
                return NULL; // Stop further backtracking
            }
            return (leftAns != NULL) ? leftAns : rightAns;
        }
        
        return NULL; // Node not found here
    }
    
    // Main function to find kth ancestor of a given node
    int kthAncestor(Node *root, int k, int node) {
        int ans = -1;
        solve(root, k, node, ans);
        return ans;
    }
};

// Utility function to build tree from level order input
Node* buildTree(vector<int> arr) {
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
    // Example tree: 1 2 3 4 5 -1 6
    vector<int> arr = {1, 2, 3, 4, 5, -1, 6};
    Node* root = buildTree(arr);
    
    Solution obj;
    int k = 2;
    int targetNode = 5;
    
    int ancestor = obj.kthAncestor(root, k, targetNode);
    cout << k << "th ancestor of node " << targetNode << " is: " << ancestor << endl;
    
    return 0;
}
