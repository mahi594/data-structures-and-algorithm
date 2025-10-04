#include <iostream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

// Structure of node
class Node {
   public:
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
    
    int countNodes(Node* tree) {
        if(tree == NULL) return 0;
        return 1 + countNodes(tree->left) + countNodes(tree->right);
    }

    bool isCBT(Node* tree, int index, int cnt) {
        if(tree == NULL) return true;
        if(index >= cnt) return false;
        //we are always filling left first
        return isCBT(tree->left,  2*index + 1, cnt) &&
               isCBT(tree->right, 2*index + 2, cnt);
    }

    bool isMAXheap(Node* tree) {
        if(tree == NULL) return true;

        // CASE 1: Leaf node
        if(tree->left == NULL && tree->right == NULL)
            return true;

        // CASE 2: Only left child
        if(tree->right == NULL) {
            return (tree->data >= tree->left->data) && isMAXheap(tree->left);
        }

        // CASE 3: Both children exist
        if(tree->data >= tree->left->data && tree->data >= tree->right->data)
            return isMAXheap(tree->left) && isMAXheap(tree->right);
        else
            return false;
    }

    bool isHeap(Node* tree) {
        int n = countNodes(tree);
        return isCBT(tree, 0, n) && isMAXheap(tree);
    }
};

// 🔹 Helper to build tree from level order input
Node* buildTree(string str) {
    if(str.length() == 0 || str[0] == 'N') return NULL;

    stringstream ss(str);
    string word;
    ss >> word;
    Node* root = new Node(stoi(word));

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // left child
        if(!(ss >> word)) break;
        if(word != "N") {
            curr->left = new Node(stoi(word));
            q.push(curr->left);
        }

        // right child
        if(!(ss >> word)) break;
        if(word != "N") {
            curr->right = new Node(stoi(word));
            q.push(curr->right);
        }
    }
    return root;
}

// 🔹 Main for testing
int main() {
    string input;
    getline(cin, input);  // Example: "10 20 30 40 60 N N"

    Node* root = buildTree(input);

    Solution sol;
    if(sol.isHeap(root))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
