#include<iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int d) {
        data = d;
        next = NULL;
        random = NULL;
    }
};





void printList(Node* head) {
    while (head != NULL) {
        cout << "Data: " << head->data;
        if (head->random)
            cout << ", Random: " << head->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        head = head->next;
    }
}




void insertAtTail(Node* &head,Node* &tail,int d)
{
    Node* temp= new Node(d);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }  
    else
    {
       tail->next=temp;
       tail=temp;
    }       
}





Node* copyList(Node * head)
{
    //step1 :> create a clone list by the next Pointers
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    Node* temp=head;

    while(temp!=NULL)
    {
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }



    //step2 :> add clone nodes between the original list
    Node* originalNode=head;
    Node* cloneNode=cloneHead;

    while(originalNode!=NULL && cloneNode!=NULL)
    {
        Node* next= originalNode->next;
        originalNode->next=cloneNode;
        originalNode=next;

        next=cloneNode->next;
        cloneNode->next=originalNode;
        cloneNode=next;
    }



    //step3 :> random pointer copy
    Node* temp2=head;
    while(temp2!=NULL)
    {
        if(temp2->next!=NULL)
        {
            if(temp2->random!=NULL)
            {
                temp2->next->random=temp2->random->next;
            }
            else
            {
                temp2->next=temp2->random;
            }
        }
         temp2=temp2->next->next;
    }



    //step4 :> revert changes done in step 2
    originalNode=head;
    cloneNode=cloneHead;

    while(originalNode!=NULL && cloneNode!=NULL)
    {
        originalNode->next=cloneNode->next;
        originalNode=originalNode->next;

        if(originalNode!=NULL)
        {
           cloneNode->next=originalNode->next;
        }
        cloneNode=cloneNode->next;
    }

    //step4 :> return clonehead;
    return cloneHead;
    


}






int main() {
    // Creating linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Setting up random pointers
    head->random = head->next->next;         // 1 -> 3
    head->next->random = head;               // 2 -> 1
    head->next->next->next->random = head->next;   // 4 -> 2
    head->next->next->next->next->random = head->next->next->next;  //5->4
    head->next->next->random = head->next->next->next->next;
    

    cout << "Original List:\n";
    printList(head);

    Node* cloned = copyList(head);

    cout << "\nCloned List:\n";
    printList(cloned);

    return 0;
}
