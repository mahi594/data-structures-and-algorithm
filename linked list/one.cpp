#include<iostream>
using namespace std;



class Node
{
    public:
    int data;
    Node* next;  //next is a pointer to another node of the same type (Node)

    Node(int data)
    {
        this ->data= data;
        this ->next= NULL;
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




void insertAtHead(Node* &head,int d)  //here head is null
{
    //create new node
    Node* temp= new Node(d);
    temp->next= head;
    head=temp;
}


void insertAtTail(Node* &tail,int d)
{
    Node* temp= new Node(d);  //temp is the new node
    tail->next= temp;
    tail=tail->next; // or tail=temp;
}


void insertAtMiddle(Node* &head,Node* &tail,int position,int d)
{
    if(position==1)  //insert at head
    {
        insertAtHead(head,d);
        return;
    }

    
    Node* temp= head; 
    int cnt=1; 

    //inserting ar last node
    

    //traversing
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert= new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;


}



void deleteNode(int position,Node* &head,Node* &tail)
{
    //deleting the head
    if(position==1)
    {
        Node *temp=head;
        head=head->next;
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

        previous->next=current->next;

        // If deleting the tail node
        if (current->next == NULL) {
            tail = previous;
        }

        current->next=NULL;
        delete current;
        
    }


}




void print(Node* &head)
{
    Node* temp= head;
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
       
}




int main()
{
    Node* node1= new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node*head= node1;
    Node*tail= node1;
    print(head);
    insertAtHead(head,12);
    print(head);
    insertAtTail(tail,20);
    print(head);
    insertAtMiddle(head,tail,2,40);
    print(head); 
    deleteNode(3,head,tail);
    print(head);
    


}