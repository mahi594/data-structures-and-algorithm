//approach 2 ::> FLOYDS CYCLE
#include<iostream>
#include<map>
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


bool isCircular(Node* head)
{
    if(head==NULL)
    {
        return true;
    }

    Node* temp = head->next;
    while(temp!=NULL && temp!=head)
    {
       temp=temp->next;   
    }
    if(temp==head)
    {
        return true;
    }
    else{
        return false;
    }
}



Node* floydDetectLopp(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
           fast=fast->next; 
        }
        slow=slow->next;

        if(slow==fast)
        {
            return slow;
        }
    }

    return NULL;

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
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Creating a singly linked list: 1 -> 2 -> 3 -> 4 -> 5
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a loop manually: 5 -> 2
    fifth->next = second;

    // isCircular will return false (it's not a true circular list)
    if (isCircular(head))
        cout << "List is circular" << endl;
    else
        cout << "List is not circular" << endl;

    // detectLopp will detect the loop
    if (floydDetectLopp(head)!= NULL)
        cout << "Loop is present (detected using map)" << endl;
    else
        cout << "No loop (detected using map)" << endl;

    // ⚠️ Avoid calling print() here as it will go into infinite loop
}
