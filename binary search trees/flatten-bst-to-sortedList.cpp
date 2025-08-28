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
    if (root == NULL) return new TreeNode(val);
    if (val < root->val) root->left = insertInBST(root->left, val);
    else root->right = insertInBST(root->right, val);
    return root;
}

// Take input until -1
TreeNode* takeInput() {
    TreeNode* root = NULL;
    int data;
    cout << "Enter elements for BST (-1 to stop): ";
    // read repeatedly until -1
    while (cin >> data && data != -1) {
        root = insertInBST(root, data);
    }
    return root;
}

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &inorderVal) {
        if (!root) return;
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right, inorderVal);
    }

    TreeNode* flatten(TreeNode* root) {
        if (!root) return NULL;
        vector<int> inorderVal;
        inorder(root, inorderVal);

        if (inorderVal.empty()) return NULL;

        TreeNode* newRoot = new TreeNode(inorderVal[0]);
        TreeNode* curr = newRoot;
        for (size_t i = 1; i < inorderVal.size(); ++i) {
            TreeNode* temp = new TreeNode(inorderVal[i]);   //here i is starting from 1
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }
        curr->left = NULL;
        curr->right = NULL;
        return newRoot;
    }
};

// print the flattened (right-skewed) tree
void printFlattened(TreeNode* root) {
    TreeNode* temp = root;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main() {
    TreeNode* root = takeInput();

    Solution sol;

    // DEBUG: show inorder values gathered from the tree
    vector<int> vals;
    sol.inorder(root, vals);
    cout << "Inorder vector (should be sorted): ";
    for (int x : vals) cout << x << " ";
    cout << endl;

    TreeNode* newRoot = sol.flatten(root);

    cout << "Flattened BST into right-skewed tree: ";
    printFlattened(newRoot);

    return 0;
}
