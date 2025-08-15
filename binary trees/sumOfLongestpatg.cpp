#include <iostream>
#include <climits>
using namespace std;

/* Structure of Node */
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Helper function to recursively find sum of longest path
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
        if (root == NULL) {
            // If we reach a NULL, check if this path is longer
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            // If same length, choose the max sum
            else if (maxLen == len) {
                maxSum = max(maxSum, sum);
            }
            return;
        }

        // Add current node’s data to sum
        sum = sum + root->data;

        // Traverse left and right subtrees
        solve(root->left, sum, maxSum, len + 1, maxLen);
        solve(root->right, sum, maxSum, len + 1, maxLen);
    }

    // Main function to return sum of longest root-to-leaf path
    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0;        // current path length
        int maxLen = 0;     // longest path length found so far
        int sum = 0;        // sum of current path
        int maxSum = INT_MIN; // max sum for the longest path

        solve(root, sum, maxSum, len, maxLen);

        return maxSum;
    }
};

// Driver code to test the function
int main() {
    /*
        Example Tree:
                 4
               /   \
              2     5
             / \     \
            7   1     2
           /           \
          6             3
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->right = new Node(2);
    root->left->left->left = new Node(6);
    root->right->right->right = new Node(3);

    Solution sol;
    cout << "Sum of Longest Root-to-Leaf Path: " 
         << sol.sumOfLongRootToLeafPath(root) << endl;

    return 0;
}
