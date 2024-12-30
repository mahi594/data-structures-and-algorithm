#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void InsertionAtTail(Node* &tail,int d)
{   
    // new node create
    Node* temp= new Node(d);
    tail->next=temp;
    tail=temp;   //updating tail

}

void print(Node * &head)     //You pass head to the print() function to print the list from the start.
{
    Node* ptr=head;

    while(ptr!=NULL)
    {
      cout<<ptr->data<<" ";
      ptr= ptr->next;  //ptr++ means 
    }

    cout<<endl;
}

    

int main()
{   //creating new node
    Node* node1=new Node(10);
   
    //head pointing to node1
    Node* tail=node1;
    Node* head=node1;
    print(head);
    InsertionAtTail(tail,12);
    print(head);
    InsertionAtTail(tail,15);
    print(head);
}

