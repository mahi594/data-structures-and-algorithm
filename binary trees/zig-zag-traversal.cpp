#include <bits/stdc++.h>
using namespace std;

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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;    

        if (root == NULL) {
            return result;
        }

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;   // flag

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size); // temporary array for current level

            // process one level
            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                // choose index based on direction
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;

                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            // add this level's result to final result
            for (auto val : ans) {
                result.push_back(val);
            }

            // flip direction for next level
            leftToRight = !leftToRight;
        }

        return result;
    }
};

int main() {
    /*
        Example Tree:
        
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> ans = sol.zigZagTraversal(root);

    cout << "Zig-Zag Traversal: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
