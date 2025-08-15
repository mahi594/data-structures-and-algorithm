#include <iostream>
#include <vector>
using namespace std;

/* Node structure */
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Helper function to find k-sum paths
    void solve(Node* root, int k, int &count, vector<int> path) {
        if (root == NULL) {
            return;
        }

        // Add current node's value to path
        path.push_back(root->data);

        // Recurse left and right
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);

        // Check for k-sum paths ending at current node
        int size = path.size();
        int sum = 0;
        for (int i = size - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k) {
                count++;
            }
        }

        // Backtrack (vector is passed by value so pop_back not mandatory here)
        path.pop_back();
    }

    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};

// Driver code to test
int main() {
    /*
        Example Tree:
                 1
               /   \
              3     -1
             / \    / \
            2   1  4   5
               /   / \
              1   1   2

        k = 5
    */

    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);

    Solution sol;
    int k = 5;
    cout << "Number of paths with sum " << k << ": " 
         << sol.sumK(root, k) << endl;

    return 0;
}
