#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void reverseLevelOrderTraversal(node* root)
{
    if (!root) return;

    queue<node*> q;
    stack<node*> s;

    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        s.push(temp);

        // push right first
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }

    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main()
{
    node* root = NULL;
    root = buildTree(root);

    // Example Input: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
    cout << "Reverse level order traversal:" << endl;
    reverseLevelOrderTraversal(root);

    return 0;
}
 