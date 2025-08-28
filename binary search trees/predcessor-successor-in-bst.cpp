#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Level separator

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Insert in BST
Node* insertInBST(Node*& root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data > root->data) {
        root->right = insertInBST(root->right, data);
    } else {
        root->left = insertInBST(root->left, data);
    }

    return root;
}

// Take input for BST
void takeInput(Node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertInBST(root, data);
        cin >> data;
    }
}

// Function to find predecessor and successor
pair<int, int> predecessorSuccessor(Node* root, int key) {
    Node* temp = root;
    int pred = -1, succ = -1;

    // Find the node with value = key
    while (temp && temp->data != key) {
        if (key < temp->data) {
            succ = temp->data; // Possible successor
            temp = temp->left;
        } else {
            pred = temp->data; // Possible predecessor
            temp = temp->right;
        }
    }

    if (temp == NULL) {
        return {pred, succ}; // Key not found, return closest pred and succ
    }

    //temp is key now

    // Predecessor: largest in left subtree
    Node* leftTree = temp->left;
    while (leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // Successor: smallest in right subtree
    Node* rightTree = temp->right;
    while (rightTree != NULL) {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST (end with -1):" << endl;
    takeInput(root);

    cout << "\nPrinting the BST (Level Order):" << endl;
    levelOrderTraversal(root);

    cout << "\nEnter the key to find its predecessor and successor: ";
    int key;
    cin >> key;

    pair<int, int> ans = predecessorSuccessor(root, key);
    cout << "Predecessor: " << ans.first << ", Successor: " << ans.second << endl;

    return 0;
}
