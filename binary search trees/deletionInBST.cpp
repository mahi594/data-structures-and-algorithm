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






//deletion in bst

Node* deleteValue(Node* root,int val)
{
    //base case
    if(root==NULL)
    {
        return root;
    }

    if(root->data==val)
    {
        //0 child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }



        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL)
        {
            Node* temp= root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL)
        {
            Node* temp= root->right;
            delete root;
            return temp;
        }



        //2 child
        if(root->left!=NULL && root->right!=NULL)
        {
            int mini= minNOde(root->right);
            root->data=mini;
            root->right=deleteValue(root->right,mini);
            return root;

        }
    }



    else if(root->data>val)
    {
        root->left= deleteValue(root->left,val);
        return root;
    }
    else
    {
        root->right=deleteValue(root->right,val);
        return root;
    }
}


int main() {
    Node* root = NULL;

    cout << "Enter data to create BST (-1 to stop):" << endl;
    takeInput(root);

    cout << "\nBST (Level Order):" << endl;
    levelOrderTraversal(root);

    int del;
    cout << "\nEnter value to delete: ";
    cin >> del;

    root = deleteValue(root, del);

    cout << "\nBST after deletion:" << endl;
    levelOrderTraversal(root);

    return 0; 
}