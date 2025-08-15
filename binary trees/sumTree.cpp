#include <bits/stdc++.h>          // GCC-specific header that includes most STL headers (not portable)
using namespace std;              // Avoids writing std:: everywhere

class Node {
public:
    int data;                     // Value at this tree node
    Node* left;                   // Pointer to left child
    Node* right;                  // Pointer to right child

    Node(int x) {
        data = x;                 // Initialize data with x
        left = nullptr;           // No left child initially
        right = nullptr;          // No right child initially
    }
};

class Solution {
public:
    // Returns a pair:
    //   first  -> true/false: is this subtree a Sum Tree?
    //   second -> int: total sum of all nodes in this subtree
    pair<bool,int> isSumTrre(Node* root)
    {
        // Base case 1: empty tree is a Sum Tree with sum = 0
        if(root == NULL) {
            return {true, 0};
        }

        // Base case 2: leaf node is a Sum Tree; sum = leaf value
        if(root->left == NULL && root->right == NULL) {
            return {true, root->data};
        }

        // Recurse on left and right subtrees to get (isSumTree, sum)
        auto leftAns = isSumTrre(root->left);
        auto rightAns = isSumTrre(root->right);

        bool isleftSumTree = leftAns.first;     // Left subtree validity
        bool isrightSumTree = rightAns.first;   // Right subtree validity

        // Current node must equal sum(left subtree) + sum(right subtree)
        bool condition = root->data == leftAns.second + rightAns.second;

        pair<bool,int> ans;                     // Prepare answer for this node
        if(isleftSumTree && isrightSumTree && condition) {
            ans.first = true;                   // This subtree is a Sum Tree
            // Subtree sum = root + leftSum + rightSum
            // (Note: when condition holds, this equals 2 * root->data)
            ans.second = root->data + leftAns.second + rightAns.second;
        }
        else {
            ans.first = false;                  // Violates the Sum Tree property
            ans.second = 0;                     // Sum is irrelevant when not Sum Tree
        }

        return ans;                             // Bubble result up
    }

    // Public wrapper: only need the boolean part
    bool isSum(Node* root) {
        return isSumTrre(root).first;
    }
};

int main() {
    /*
           26
          /  \
        10    3
       / \     \
      4   6     3
    */

    // Build the example tree
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    // Check and print the result
    Solution sol;
    if (sol.isSum(root)) {
        cout << "Tree is a Sum Tree\n";
    } else {
        cout << "Tree is NOT a Sum Tree\n";
    }

    return 0;
}
