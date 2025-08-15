#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
private:
    pair<int, bool> checkBalanced(Node* root) {
        // Base case: empty tree is balanced, height = 0
        if (root == NULL) {
            return {0, true};
        }

        // Check left subtree
        pair<int, bool> left = checkBalanced(root->left);
        // Check right subtree
        pair<int, bool> right = checkBalanced(root->right);

        // Height of current node
        int height = max(left.first, right.first) + 1;

        // Balanced if left & right subtrees are balanced and height diff <= 1
        bool balanced = left.second && right.second && abs(left.first - right.first) <= 1;

        return {height, balanced};
    }

public:
    bool isBalanced(Node* root) {
        return checkBalanced(root).second;
    }
};

// Helper to build a balanced example tree
Node* buildExampleTree() {
    /*
        Balanced:
              1
             / \
            2   3
           / \
          4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main() {
    Solution sol;

    // Example 1: Balanced
    Node* root1 = buildExampleTree();
    cout << "Tree 1 is balanced? " << (sol.isBalanced(root1) ? "Yes" : "No") << endl;

    // Example 2: Unbalanced
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    root2->left->left->left = new Node(4); // Skewed
    cout << "Tree 2 is balanced? " << (sol.isBalanced(root2) ? "Yes" : "No") << endl;

    return 0;
}
 