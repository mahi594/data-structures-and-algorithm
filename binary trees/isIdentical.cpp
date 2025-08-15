#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    bool isIdentical(Node* root1, Node* root2) {
        // Base case: both are NULL
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        
        // One is NULL, the other is not
        if (root1 == NULL || root2 == NULL) {
            return false;
        }
        
        // Recursively check left & right subtrees
        bool left = isIdentical(root1->left, root2->left);
        bool right = isIdentical(root1->right, root2->right);
        
        // Current node values must match
        bool value = (root1->data == root2->data);
        
        return left && right && value;
    }
};

int main() {
    /*
        Tree 1:        Tree 2:
            1              1
           / \            / \
          2   3          2   3
    */
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    Solution sol;
    if (sol.isIdentical(root1, root2)) {
        cout << "Trees are identical\n";
    } else {
        cout << "Trees are NOT identical\n";
    }

    return 0;
}
