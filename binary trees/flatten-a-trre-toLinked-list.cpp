#include <iostream>
using namespace std;

// Definition of Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void flatten(Node* root) {
        Node* current = root;

        while (current != NULL) {
            if (current->left) {
                Node* pred = current->left;

                // find the rightmost node of left subtree
                while (pred->right) {
                    pred = pred->right;
                }

                // attach current's right to rightmost node of left subtree
                pred->right = current->right;

                // move left subtree to right
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};

// Helper function to print flattened tree
void printFlattened(Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

// Example usage
int main() {
    /* Example tree:
            1
           / \
          2   5
         / \   \
        3   4   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    Solution s;
    s.flatten(root);

    cout << "Flattened tree: ";
    printFlattened(root);

    return 0;
}
