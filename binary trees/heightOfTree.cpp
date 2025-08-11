#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Solution class
class Solution {
public:
    // Height in terms of NODES
    int heightNodes(Node* node) {
        if (node == NULL) return 0; // base case: empty tree has 0 nodes in height
        int leftHeight = heightNodes(node->left);
        int rightHeight = heightNodes(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    // Height in terms of EDGES
    int heightEdges(Node* node) {
        if (node == NULL) return -1; // base case: empty tree has -1 edges
        int leftHeight = heightEdges(node->left);
        int rightHeight = heightEdges(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    /*
         1
        / \
       2   3
      /
     4
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    Solution obj;

    cout << "Height (in nodes): " << obj.heightNodes(root) << endl;
    cout << "Height (in edges): " << obj.heightEdges(root) << endl;

    return 0;
}
