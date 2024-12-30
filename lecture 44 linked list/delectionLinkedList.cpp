#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

    //destructor
    ~Node()
    {
        int value = this->data;
        //memory free
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
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

void InsertionAtTail(Node* &tail,int d)
{   
    // new node create
    Node* temp= new Node(d);
    tail->next=temp;
    tail=temp;

}

void InsertionAtPosition(Node* &tail,Node* &head,int position,int d)
{   
    //1. inserting at first
    if(position==1)
    {
        InsertionAtHead(head,d);
        return;
    }


    //2. inserting at any position
    // new node create
    Node* temp= head;
    int count=1;
    
    while(count<position-1)
    {
        temp=temp->next;    //traversing till position
        count++;    
    }


     //3. inserting at end 
      if(temp->next==NULL)
      {
        InsertionAtTail(tail,d);   // updating tail
        return; 

      }
    //creating a node for d
    Node* nodetoInsert=new Node(d);
    nodetoInsert->next=temp->next;
    temp->next=nodetoInsert;
   
}


void deletionNode(int position, Node* &head)
{

    //deleting first or start node
    if(position==1)
    {
        Node* temp=head;   //pointer
         head=head->next;
         temp->next=NULL; 
         //memory free of first node
         delete temp;
    }

    else{
        //deleting any middle node or last  node
        Node* current= head;
        Node* previous= NULL;

        int count=1;
        while(count<position)     //taversing to the position
        {
            previous=current;
            current=current->next;
            count++;
        }

        previous->next=current->next;
        current->next=NULL; 
          //deleting element
        delete current;
    }
    
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

    InsertionAtPosition(tail,head,1,22);
    print(head); 

    deletionNode(2,head);
    print(head);
}

