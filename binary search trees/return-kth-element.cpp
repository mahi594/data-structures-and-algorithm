#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to find kth smallest
    int solve(TreeNode* root, int &i, int k) {
        if (root == nullptr) {
            return -1;
        }

        // Search in left subtree
        int left = solve(root->left, i, k);
        if (left != -1) {
            return left;
        }

        // Current node
        i++;
        if (i == k) {
            return root->val;
        }

        // Search in right subtree
        return solve(root->right, i, k);
    }


    

    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return solve(root, i, k);
    }
};

// Utility function to create an example BST
TreeNode* createExampleTree() {
    /*
        Example BST:
            3
           / \
          1   4
           \
            2
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createExampleTree();

    int k = 1;
    cout << "Kth smallest element (k=" << k << "): " << sol.kthSmallest(root, k) << endl;

    k = 3;
    cout << "Kth smallest element (k=" << k << "): " << sol.kthSmallest(root, k) << endl;

    return 0;
}
