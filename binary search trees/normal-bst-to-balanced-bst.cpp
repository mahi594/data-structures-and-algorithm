#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
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

class Solution 
{
public:
    void inorder(TreeNode* root, vector<int> &inorderVal) 
    {
        if (!root) return;
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right, inorderVal);
    }


    TreeNode* inorderToBST(int s,int e,vector<int> &inorderVal)
    {
        //base case
        if(s>e)
        {
            return NULL;
        }

        int mid= (s+e)/2;
        TreeNode* root= new TreeNode(inorderVal[mid]);
        root->left= inorderToBST(s,mid-1,inorderVal);
        root->right= inorderToBST(mid+1,e,inorderVal);
        return root;
    }


    TreeNode* balancedBST(TreeNode* root)
    {
        vector<int> inorderVal;
        //store inorder ->store values
        inorder(root,inorderVal);

        return inorderToBST(0,inorderVal.size()-1,inorderVal);
    }

   
};



int main() {
    TreeNode* root = takeInput();

    Solution sol;

     vector<int> vals;
    sol.inorder(root, vals);
    cout << "Original BST Inorder (sorted): ";
    for (int x : vals) cout << x << " ";
    cout << endl;

    // Convert BST into Balanced BST
    TreeNode* newRoot = sol.balancedBST(root);

    // Display the new tree's inorder (it should be the same as original)
    vector<int> balancedVals;
    sol.inorder(newRoot, balancedVals);
    cout << "Balanced BST Inorder: ";
    for (int x : balancedVals) cout << x << " ";
    cout << endl;

    return 0;
}
