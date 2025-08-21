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





int minNOde(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    Node* temp= root;

    while(temp->left!=NULL)
    {
       temp=temp->left;
    }

    return temp->data;
}



int maxNOde(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    Node* temp= root;

    while(temp->right!=NULL)
    {
       temp=temp->right;
    }

    return temp->data;
}





int main()
{
    Node* root=NULL;

    cout<<"enter data to  create bst"<<endl;
    takeInput(root);

    cout<<"printing the bst"<<endl;
    levelOrderTraversal(root);

    cout<<"minmum node";
    cout<<minNOde(root)<<endl;

    cout<<"maxmum node";
    cout<<maxNOde(root)<<endl;

    return 0; 
}