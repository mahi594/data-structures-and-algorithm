#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*prev;
    Node*next;

    //constructor
    Node(int d)
    {
       this->data=d;
       this->prev=NULL;
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


void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}


int getLength(Node* head)
{
    int len=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    cout << len << endl;
}




void insertAtHead(Node* &head,Node* &tail,int d)
{

    //empty list
    if(head==NULL)
    {
        Node* temp= new Node(d);
        head=temp;
        tail=temp;
    }
    else{
       Node* temp= new Node(d);
       temp->next=head;
       head->prev=temp;
      head=temp;
    }
   
}



void insertAtTail(Node* &tail,Node* &head,int d)
{
    //empty list
    if(tail==NULL)
    {
        Node* temp= new Node(d);
        tail=temp;
        head=temp;
    }
    else{

        Node* temp= new Node(d);  //temp is the new node
       tail->next= temp;
       temp->prev=tail;
    tail=tail->next; // or tail=temp;
    }
    
}



void insertAtMiddle(Node* &head,Node* &tail,int position,int d)
{
    if(position==1)  //insert at head
    {
        insertAtHead(head,tail,d);
        return;
    }

    
    Node* temp= head; 
    int cnt=1; 

    

    //traversing
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }


    //inserting ar last node
    if(temp->next==NULL)
    {
        insertAtTail(tail,head,d);
        return;
    }


    Node* nodeToInsert= new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;


}




void deleteNode(int position,Node* &head,Node* &tail)
{
    //deleting the head
    if(position==1)
    {
        Node *temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;  //free
    }

    //deletion at middle or end
    else{
        Node *current=head;
        Node *previous=NULL;
        int cnt=1;
        while(cnt< position)
        {
            previous=current;
            current=current->next;
            cnt++;
        
        }

       

        // If deleting the tail node
        if (current->next == NULL) {
            tail = previous;
            previous->next = NULL;
        }

         else
        {
            previous->next = current->next;
            current->next->prev = previous;
        }
        current->next=NULL;
        current->prev=NULL;
        delete current;
        
    }


}





int main()
{
    //Node* node1= new Node(10);
    Node* head= NULL;
    Node* tail= NULL;
    print(head);
    getLength(head);
    insertAtHead(head,tail,20);
    print(head);
    insertAtHead(head,tail,30);
    print(head);
    insertAtHead(head,tail,40);
    print(head);
    insertAtTail(tail,head,60);
    print(head);
    insertAtMiddle(head,tail,1,80);
    print(head);
    insertAtMiddle(head,tail,4,70);
    print(head);
    insertAtMiddle(head,tail,7,80);
    print(head);
    deleteNode(7,head,tail);
    print(head);
}