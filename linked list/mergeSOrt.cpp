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

Node* getMiddle(Node* head)
{
    Node* slow= head;
    Node* fast= head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }

    return slow;
}








Node* solve(Node* first,Node*second)
{
    // if only one node is present in each list
    if(first->next==NULL)
    {
        first->next=second;
        return first;
    }


     Node* current1=first;
     Node* next1=first->next;
     Node* current2=second;

     while(next1!=NULL && current2!=NULL)
     {
        if((current2->data >= current1->data)  && (current2->data <= next1->data))
        {
             current1->next= current2; //1 node addition
             Node* next2=current2->next;//2 node addition
             current2->next=next1;  //3 node addition
             current1=current2;   //4 update pointers
             current2=next2;   //5 update pointers

        }

        else{
            //current 1 and next1 ko aage badna
            current1=next1;
            next1=next1->next;

            if(next1==NULL)
            {
                current1->next= current2;
                return first;
            } 
        }
     }
     return first;
}




Node* merge(Node* first,Node*second )
{
    if(first==NULL)
    {
        return second;
    }
    if(second==NULL)
    {
        return first;
    }

    if(first->data<= second->data)
    {
        return solve(first,second);
    }
    else{
       return solve(second,first);
    }
}


Node* mergeSort(Node* head)
{
    //base case
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    //break lionked lost into two halves
    Node* mid=getMiddle(head);

    Node* left= head;
    Node* right= mid->next;
    mid->next=NULL;
    
    //recursion call to sort
    left=mergeSort(left);
    right=mergeSort(right);

    //merge both left and right halves
    Node* result= merge(left,right);
    
    return result;
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



int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 9);
    insertAtTail(tail, 12);
    insertAtTail(tail, 16);
    insertAtTail(tail, 20);
    insertAtTail(tail, 8);
    insertAtTail(tail, 11);
    insertAtTail(tail, 14);
    insertAtTail(tail, 21);
    insertAtTail(tail, 23);
    

    cout << "Original List: ";
    print(head);

   

    Node* merged = mergeSort(head);

    cout << "Sorted List: ";
    print(merged);

    return 0;
}
