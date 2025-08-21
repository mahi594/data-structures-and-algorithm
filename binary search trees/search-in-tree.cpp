#include<iostream>
#include<queue>
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



//insertion in  binary serach tree



void levelOrderTraversal(Node* root)
{
    if (root == NULL) {   
        return;
    }

     queue<Node*>q;
     q.push(root);
     q.push(NULL);    //seperator

     while(!q.empty())
     {
        Node* temp=q.front();
        
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


Node* insertInBST(Node* &root,int data)
{
    //base case
    if(root==NULL)
    {
        root= new Node(data);
        return root;
    }

    if(data>root->data)
    {
        //right part insertion
        root->right= insertInBST(root->right,data);
    }
    else{
        //left part insertion
        root->left= insertInBST(root->left,data);
    }

    return root;

}




void takeInput(Node* &root)
{
    int data;
    cin>>data;  //for the root node only

    while(data != -1)
    {
       root=insertInBST(root,data);
       cin>>data;   //for all other remaining nodes
    }
}




bool searchInBST(Node* &root,int x)
{
    //base case
    if(root==NULL)
    {
        return false;
    }
    
    if(root->data==x)
    {
        return true;
    }

    if(root->data > x)
    {
        return searchInBST(root->left,x);
    }

    else{
        return searchInBST(root->right,x);
    }

}


//iterative way
bool searchInBSTIterative(Node* &root,int x)
{
    Node* temp=root;

    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            return true;
        }
        
        if(temp->data>x)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }

    return false;

}




int main()
{
    Node* root=NULL;

    cout<<"enter data to  create bst"<<endl;
    takeInput(root);

    cout<<"printing the bst"<<endl;
    levelOrderTraversal(root);

    int element;
    cin>>element;

    cout << "Is element present in tree? ";
    if (searchInBST(root, element)) {
       cout << "Yes" << endl;
    }
    else {
    cout << "No" << endl;
    } 


    return 0; 
}