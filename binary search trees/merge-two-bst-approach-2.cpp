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

class Solution {
public:
    // Convert BST into DLL (inorder traversal)
    void convertIntoDLL(TreeNode* root, TreeNode* &head) {
        if (root == NULL) return;

        convertIntoDLL(root->right, head);

        root->right = head;
        if (head != NULL) {
            head->left = root;
        }
        head = root;

        convertIntoDLL(root->left, head);
    }

    // Merge two sorted DLLs
    TreeNode* mergeLinkedList(TreeNode* head1, TreeNode* head2) {
        TreeNode* head = nullptr;
        TreeNode* tail = nullptr;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                if (head == NULL) {
                    head = tail = head1;
                    head1 = head1->right;
                } else {
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                    head1 = head1->right;
                }
            } else {
                if (head == NULL) {
                    head = tail = head2;
                    head2 = head2->right;
                } else {
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                    head2 = head2->right;
                }
            }
        }

        while (head1 != NULL) {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }

        while (head2 != NULL) {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }

        return head;
    }

    // Count nodes in DLL
    int countNodes(TreeNode* head) {
        int cnt = 0;
        TreeNode* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->right;
        }
        return cnt;
    }

    // Convert sorted DLL to BST
    TreeNode* sortedLinkedListToBST(TreeNode* &head, int n) {
        if (n <= 0 || head == NULL) return NULL;

        TreeNode* left = sortedLinkedListToBST(head, n / 2);

        TreeNode* root = head;
        root->left = left;

        head = head->right;

        root->right = sortedLinkedListToBST(head, n - n / 2 - 1);
        return root;
    }

    // Merge 2 BSTs
    TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {
        // Step1: Convert both BSTs into DLL
        TreeNode* head1 = NULL;
        convertIntoDLL(root1, head1);
        if (head1) head1->left = NULL;

        TreeNode* head2 = NULL;
        convertIntoDLL(root2, head2);
        if (head2) head2->left = NULL;

        // Step2: Merge 2 sorted DLLs
        TreeNode* head = mergeLinkedList(head1, head2);

        // Step3: Convert merged DLL into balanced BST
        return sortedLinkedListToBST(head, countNodes(head));
    }
};

// Utility function to print BST (Level Order)
void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            TreeNode* temp = q.front();
            q.pop();
            cout << temp->val << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}



int main() {
    Solution sol;

     // BST1 = [2,1,4]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    // BST2 = [1,null,3,null,6]
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(6);


    TreeNode* mergedRoot = sol.mergeBST(root1, root2);

    cout << "Level Order Traversal of Merged BST:" << endl;
    printLevelOrder(mergedRoot);

    return 0;
}
