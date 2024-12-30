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

void InsertionAtHead(Node* &head,int d)
{
    //1.creating new node
    Node* temp=new Node(d);
    //2. assinging temp ka next to head(address of next node) 
    temp->next=head;
    //3.  in stating head is pointing to node 1 now it will point to temp
    head=temp;

}


void print(Node * &head)
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
    Node* head=node1;
    print(head);

    InsertionAtHead(head,12 );
    
    print(head); 
 
    InsertionAtHead(head,15 );
    
    print(head); 
}