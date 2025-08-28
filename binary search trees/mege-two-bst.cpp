#include <iostream>
#include <vector>
#include <queue>
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




class Solution 
{
public:

void inorder(TreeNode* root,vector<int> &in)
{
     if(root== NULL)
     {
        return;
     }
     inorder(root->left,in);
     in.push_back(root->val);
     inorder(root->right,in);
}


vector<int> mergeArrays(vector<int> a,vector<int> b)
{
    vector<int> ans(a.size() + b.size());
    int i=0,j=0;
    int k=0;

    while(i<a.size() && j< b.size())
    {
        if(a[i]<b[j])
        {
            ans[k++]=a[i]; 
            i++;
        }
        else
        {
            ans[k++]=b[j]; 
            j++;
        }
    }
    while(i<a.size())
    {
        ans[k++]=a[i]; 
        i++;
    }
    while(j<b.size())
    {
        ans[k++]=b[j]; 
        j++;
    }

    return ans;
}



TreeNode *inorderToBST(int s,int e,vector<int> &in)
{
    if(s>e)
    {
        return NULL;
    }
    int mid= (s+e)/2;
    TreeNode* root= new TreeNode(in[mid]);
    root->left= inorderToBST(s,mid-1,in);
    root->right= inorderToBST(mid+1,e,in);
    return root;
}



TreeNode *mergeBST(TreeNode* root1,TreeNode* root2)
{
    //step1:> store inorder
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    //step2:> mergeArray
    vector<int> mergedArray= mergeArrays(bst1,bst2);

    //step3:> array to bst
     return inorderToBST(0,mergedArray.size()-1,mergedArray);
}   
};




// Utility function to print BST (Level Order)
void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        while (n--) 
        {
            TreeNode* temp = q.front();
            q.pop();
            cout << temp->val << " ";

            if (temp->left)
            {
                 q.push(temp->left);
            }     
            if (temp->right) 
            {
                q.push(temp->right);
            }

        }
        cout << endl;
    }
}

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
    TreeNode* root2 = createExampleTree2();

    TreeNode* mergedRoot = sol.mergeBST(root1, root2);

    cout << "Level Order Traversal of Merged BST:" << endl;
    printLevelOrder(mergedRoot);

    return 0;
}