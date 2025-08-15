#include <bits/stdc++.h>
using namespace std;

// ----------------------
// Node structure for the Binary Tree
// ----------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// ----------------------
// Solution class for Top View
// ----------------------
class Solution {
  public:
    vector<int> topView(Node *root) {
        
        vector<int> ans;
        
        // Base case: if tree is empty
        if (root == NULL) {
            return ans;
        }
        
        // map<hd, node_value> to store first node for each horizontal distance
        map<int, int> topNode; 
        
        // queue to do BFS: stores (node pointer, horizontal distance)
        queue<pair<Node*, int>> q;  
        
        // Start BFS from root with horizontal distance = 0
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // If hd is not already in map, insert it (first node seen from top)
            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = frontNode->data;
            }
            
            // Left child → hd - 1
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            
            // Right child → hd + 1
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }
        
        // Collect values from leftmost hd to rightmost hd
        for (auto i : topNode) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};

// ----------------------
// Helper function to build tree from level-order input
// ----------------------
Node* buildTree(vector<string> nodes) {
    if (nodes.empty() || nodes[0] == "N") return NULL;
    
    Node* root = new Node(stoi(nodes[0]));
    queue<Node*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front();
        q.pop();
        
        // Left child
        if (nodes[i] != "N") {
            curr->left = new Node(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;
        
        // Right child
        if (i < nodes.size() && nodes[i] != "N") {
            curr->right = new Node(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// ----------------------
// Main function
// ----------------------
int main() {
    // Example input: level-order representation
    // N means NULL
    vector<string> treeNodes = {"1", "2", "3", "4", "5", "6", "7", "N", "N", "N", "N", "N", "8", "N", "9"};
    
    Node* root = buildTree(treeNodes);
    
    Solution sol;
    vector<int> result = sol.topView(root);
    
    cout << "Top View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
