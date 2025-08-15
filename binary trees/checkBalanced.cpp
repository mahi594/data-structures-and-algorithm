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

// Your Solution class
class Solution {
private:
    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(Node* root) {
        if (root == NULL) {
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool difference = abs(height(root->left) - height(root->right)) <= 1;

        if (left && right && difference) {
            return true;
        } else {
            return false;
        }
    }
};

// Helper function to build a small example tree
Node* buildExampleTree() {
    /*
        Balanced tree:
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

    // Example 1: Balanced tree
    Node* root1 = buildExampleTree();
    cout << "Tree 1 is balanced? " << (sol.isBalanced(root1) ? "Yes" : "No") << endl;

    // Example 2: Unbalanced tree
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    root2->left->left->left = new Node(4); // Skewed
    cout << "Tree 2 is balanced? " << (sol.isBalanced(root2) ? "Yes" : "No") << endl;

    return 0;
}
