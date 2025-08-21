#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    // Function to find position of element in inorder
    int findPosition(vector<int>& inorder, int element, int n) {
        for (int i = 0; i < n; i++) {
            if (inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }

    // Recursive function to build the tree
    Node* solve(vector<int>& inorder, vector<int>& preorder,
                int& index, int inorderStart, int inorderEnd, int n) {

        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }

        int rootElement = preorder[index++];
        Node* root = new Node(rootElement);

        int position = findPosition(inorder, rootElement, n);

        root->left = solve(inorder, preorder, index, inorderStart, position - 1, n);
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n);

        return root;
    }

    // Wrapper function
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int preorderIndex = 0;
        int n = preorder.size();
        Node* ans = solve(inorder, preorder, preorderIndex, 0, n - 1, n);
        return ans;
    }
};

// Function to print tree level by level
void printLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl; // next level
    }
}

int main() {
    // Example input
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};

    Solution s;
    Node* root = s.buildTree(inorder, preorder);

    cout << "Level Order Traversal of Tree:" << endl;
    printLevelOrder(root);

    return 0;
}
