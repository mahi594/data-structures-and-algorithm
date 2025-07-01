#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    //constructor
    Node(int d)
    {
       this->data=d;
       this->next=NULL;
    }

    //dectructor
    ~Node()
    {
        int value=this->data;
        //memeory free
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free"<<value<<endl;
    }
    
};




void insertNode(Node* &tail,int element,int d)
{   
    //empty list
    if(tail==NULL)
    {
        Node* temp= new Node(d);
        tail=temp;
        temp->next=temp; //as circular
    }    

    //assuming that the element is present in the list
    else
    {
      Node* current=tail;
    
    // till we dont get the element
    while(current->data!= element)
    {
       current=current->next;
    }

    //found the element
      Node* temp= new Node(d);
      temp->next=current->next;
      current->next=temp;
    }
}




void deleteNode(Node* &tail,int element)
{
    //empty list
    if(tail==NULL)
    {
      cout<<"list is empty"<<endl;
      return;
    }
    else
    {
        //assuming that value is present in the list
        Node* previous=tail;
        Node* current=previous->next;

        while(current->data!=element)
        {
            current=current->next;
            previous=previous->next;
        }

        previous->next=current->next;

        //one node linked list
        if(current==previous)
        {
            tail=NULL;
        }

        //if node are>=2
        if(tail==current)
        {
            tail=previous;      //as we want update our tail
        }
        current->next=NULL;
        delete current;



    }
}








void print(Node* tail)
{
    Node* temp=tail;
    do
    {
       cout<<tail->data<<" ";
       tail=tail->next;
    } 
    
    
    while(tail!=temp);  //print till we again got at the tail
    
    cout << endl;
}









int main()
{
    //Node* node1= new Node(10);
    
    Node* tail= NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,6);
    print(tail);
    insertNode(tail,3,4);
    print(tail);
    insertNode(tail,5,7);
    print(tail);
    insertNode(tail,6,8);
    print(tail);
    insertNode(tail,8,9);
    print(tail);
    insertNode(tail,3,2);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    
}