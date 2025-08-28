#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Insert function to build BST
TreeNode* insertInBST(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertInBST(root->left, val);
    } else {
        root->right = insertInBST(root->right, val);
    }
    return root;
}

// Take input until -1
TreeNode* takeInput() {
    TreeNode* root = NULL;
    int data;
    cout << "Enter elements for BST (-1 to stop): ";
    cin >> data;
    while (data != -1) {
        root = insertInBST(root, data);
        cin >> data;
    }
    return root;
}

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &inorderVal) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right, inorderVal);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;
        inorder(root, inorderVal);

        int i = 0, j = inorderVal.size() - 1;
        while (i < j) {
            int sum = inorderVal[i] + inorderVal[j];
            if (sum == k) {
                return true;
            } else if (sum > k) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

int main() {
    TreeNode* root = takeInput();
    
    int k;
    cout << "Enter target sum: ";
    cin >> k;

    Solution obj;
    if (obj.findTarget(root, k)) {
        cout << "Pair with sum " << k << " exists in BST." << endl;
    } else {
        cout << "No pair with sum " << k << " exists in BST." << endl;
    }

    return 0;
}
