#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    // Traverse left boundary (excluding leaf nodes)
    void traversalLeft(Node* root, vector<int> &ans) {
        if (root == NULL) return;

        // Stop if it's a leaf node
        if (root->left == NULL && root->right == NULL) return;

        ans.push_back(root->data);

        if (root->left) {
            traversalLeft(root->left, ans);
        } else {
            traversalLeft(root->right, ans);
        }
        
    }

    // Traverse all leaf nodes
    void traversalLeaf(Node* root, vector<int> &ans) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }

        traversalLeaf(root->left, ans);
        traversalLeaf(root->right, ans);
    }

    // Traverse right boundary (excluding leaf nodes) in reverse order
    void traversalRight(Node* root, vector<int> &ans) {
        if (root == NULL) return;

        // Stop if it's a leaf node
        if (root->left == NULL && root->right == NULL) return;

        if (root->right) {
            traversalRight(root->right, ans);
        } else {
            traversalRight(root->left, ans);
        }

        ans.push_back(root->data); // Added after recursion to reverse
    }

    // Main boundary traversal function
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;

        ans.push_back(root->data);

        // 1. Left boundary
        traversalLeft(root->left, ans);

        // 2. Leaf nodes
        traversalLeaf(root->left, ans);
        traversalLeaf(root->right, ans);

        // 3. Right boundary
        traversalRight(root->right, ans);

        return ans;
    }
};

// Main function to test
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
           / \  / \
          7  8 9  10
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    root->right->right = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    Solution sol;
    vector<int> result = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
