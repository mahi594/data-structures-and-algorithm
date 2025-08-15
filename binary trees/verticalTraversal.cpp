#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        
        map<int, map<int, vector<int>>> nodes;  // mapping: hd -> level -> list of nodes
        queue<pair<Node*, pair<int,int>>> q;    // node, hd, level
        
        vector<vector<int>> ans;
        
        if (root == NULL) {
            return ans;
        }
        
        q.push(make_pair(root, make_pair(0, 0)));
        
        while (!q.empty()) {
            pair<Node*, pair<int,int>> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            nodes[hd][level].push_back(frontNode->data);
            
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));
            }
            
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
            }
        }
        
        // Convert map structure into ans
        for (auto i : nodes) {       // hd
            vector<int> col;
            for (auto j : i.second) {    // level
                for (auto k : j.second) {    // vector<int>
                    col.push_back(k);
                }
            }
            ans.push_back(col); // push the whole column into ans
        }
        
        return ans;
    }
};

// Helper function to build a simple tree
Node* buildSampleTree() {
    /*
         1
        / \
       2   3
      / \   \
     4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = buildSampleTree();
    Solution sol;
    vector<vector<int>> result = sol.verticalOrder(root);
    
    cout << "Vertical Order Traversal:" << endl;
    for (auto col : result) {
        for (auto val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
