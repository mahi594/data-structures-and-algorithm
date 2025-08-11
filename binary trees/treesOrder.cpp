#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root)
{
    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;

    if(data==-1)
    {
        return NULL;
    }

    root= new node(data);

    cout<<"enter data for inserting in left "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data for inserting in right "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root)
{
     queue<node*>q;
     q.push(root);
     q.push(NULL);    //seperator

     while(!q.empty())
     {
        node* temp=q.front();
        
        q.pop();

        if(temp==NULL)  // one level is completed
        {
            cout<<endl;

            if(!q.empty())  // queue still has some child npods
            {
                q.push(NULL);
            }
        }

    else{
        cout<<temp->data<<" ";
    
     if(temp->left)
     {
        q.push(temp->left);
     }

      if(temp->right)
     {
        q.push(temp->right);
     }
    }

 } 

}




void inorder(node* root)
{
    //base case
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


void preorder(node* root)
{
    //base case
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}


void postorder(node* root)
{
    //base case
    if(root==NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}





int main()
{
    node* root= NULL;
    root=buildTree(root);
  
    //level order 1 2 4 -1 -1 5 -1 -1 3
    //6 -1 -1 -1 
    cout<<"level order traversal"<<endl;
    levelOrderTraversal(root);

    cout<<"inorder traversal"<<endl;
    inorder(root);
    cout<<endl;

    cout<<"preorder traversal"<<endl;
    preorder(root);
    cout<<endl;

    cout<<"postorder traversal"<<endl;
    postorder(root);

    return 0;
}