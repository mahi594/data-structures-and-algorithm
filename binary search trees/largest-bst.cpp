#include<iostream>
#include<climits>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};


class info
{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};



info solve(Node* root, int &ans)
{
     //base case
     if(root== NULL)
     {
        return {INT_MIN,INT_MAX,true,0};
     }

     info left= solve(root->left,ans);
     info right= solve(root->right,ans);

     info currentNode;

     currentNode.size= left.size+ right.size + 1;
     currentNode.maxi= max(root->data,right.maxi);
     currentNode.mini= min(root->data,left.mini);

     if(left.isBST && right.isBST  && (root->data >left.maxi && root->data < right.mini))
     {
        currentNode.isBST= true;
     }
     else
     {
        currentNode.isBST= false;
     }

     //update answer
     if(currentNode.isBST)
     {
        ans= max(ans, currentNode.size);
     }

     return currentNode;

}



int largestBST(Node* root)
{
     int maxsize=0;
     info temp= solve(root,maxsize);
     return maxsize;
}



int main()
{
    /* Example Tree:
    
              50
             /  \
           30    60
          /  \   / \
        5   20  45  70
                   / \
                 65   80

    Largest BST here is:
              60
             /  \
           45    70
                /  \
              65    80

    Size of Largest BST = 5
    */

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(45);
    root->right->right = new Node(70);

    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    cout << "Size of the largest BST is: " << largestBST(root) << endl;

    return 0;
}