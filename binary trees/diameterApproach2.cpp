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


    pair<int,int> diameterFast(Node * root)
    {

        //first is diameter and second is height

        if (root == NULL) {
            pair<int,int> p=make_pair(0,0);
            return p;
        }

        pair<int,int> left= diameterFast(root->left);
        pair<int,int> right= diameterFast(root->right);
        
        int option1 = left.first;
        int option2 = right.first;
        int option3 = left.second + right.second + 1 ; // nodes

        pair<int,int> ans;
        ans.first= max(option1, max(option2, option3));

        ans.second=max(left.second,right.second)+1;

        return ans;

    }

    int diameter(Node* root)
    {
        return diameterFast(root).first;
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
