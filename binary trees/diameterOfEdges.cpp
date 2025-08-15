#include <bits/stdc++.h>
using namespace std;

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

Node* newNode(int val) {
    return new Node(val);
}

class Solution {
private:
    // Height in terms of NODES
    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
    
public:
    int diameter(Node* root) {
        if (root == NULL) {
            return 0;
        }
        
        int option1 = diameter(root->left);
        int option2 = diameter(root->right);
        int option3 = height(root->left) + height(root->right); // edges

        return max(option1, max(option2, option3));
    }
};

int main() {
    // Example tree:
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    Solution sol;
    cout << "Diameter (in edges): " << sol.diameter(root) << endl;

    return 0;
}
