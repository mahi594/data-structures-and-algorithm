#include <iostream>
using namespace std;

/* Definition of Node */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to find LCA of two nodes
    Node* lca(Node* root, int n1, int n2) {
        // Base case
        if (root == NULL) {
            return NULL;
        }

        // If root is one of n1 or n2, return root
        if (root->data == n1 || root->data == n2) {
            return root;
        }

        // Search in left and right subtrees
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);

        // If both sides return non-null, current node is LCA
        if (leftAns != NULL && rightAns != NULL) {
            return root;
        }
        // If only left subtree has answer
        else if (leftAns != NULL && rightAns == NULL) {
            return leftAns;
        }
        // If only right subtree has answer
        else if (leftAns == NULL && rightAns != NULL) {
            return rightAns;
        }
        // If neither subtree has answer
        else {
            return NULL;
        }
    }
};

// Driver code
int main() {
    /*
        Example tree:
                 3
               /   \
              5     1
             / \   / \
            6   2 0   8
               / \
              7   4
    */

    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution sol;

    int n1 = 5, n2 = 4;
    Node* ans = sol.lca(root, n1, n2);

    if (ans != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ans->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}
