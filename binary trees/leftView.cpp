#include <iostream>
#include <vector>
using namespace std;

/* Structure of Node */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    // Helper function for recursive traversal
    void solve(Node *root, vector<int> &ans, int level) {
        if (root == NULL) {
            return; // Base case: reached empty node
        }

        // If this is the first time visiting this level
        if (level == ans.size()) {
            ans.push_back(root->data);
        }

        // First go left (because we want left view)
        solve(root->left, ans, level + 1);
        // Then go right
        solve(root->right, ans, level + 1);
    }

    // Function to return left view
    vector<int> leftView(Node *root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

// Driver code to test
int main() {
    /*
        Example Tree:
                 1
               /   \
             2       3
              \     / \
               4   5   6
                  /
                 7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    Solution sol;
    vector<int> result = sol.leftView(root);

    cout << "Left View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
