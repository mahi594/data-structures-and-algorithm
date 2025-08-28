#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
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
    bool isBST(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val > min && root->val < max) {
            bool left = isBST(root->left, min, root->val);
            bool right = isBST(root->right, root->val, max);
            return left && right;
        } else {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};

// Utility function to create a simple tree for testing
TreeNode* createExampleTree1() {
    // Example 1: root = [2,1,3]
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    return root;
}

TreeNode* createExampleTree2() {
    // Example 2: root = [5,1,4,null,null,3,6]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    Solution sol;

    TreeNode* root1 = createExampleTree1();
    cout << "Example 1: " << (sol.isValidBST(root1) ? "true" : "false") << endl;

    TreeNode* root2 = createExampleTree2();
    cout << "Example 2: " << (sol.isValidBST(root2) ? "true" : "false") << endl;

    return 0;
}
