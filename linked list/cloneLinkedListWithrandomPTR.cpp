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

    Node* temp= head;  //original list head

    while(temp!=NULL)
    {
       insertAtTail(cloneHead,cloneTail,temp->data);  
       temp=temp->next; 
    }

    //step2 :> create map
    unordered_map<Node*,Node*> oldToNew;
    Node* orignalNode=head;
    Node* cloneNode=cloneHead;   //clone list ka head
    while(orignalNode!=NULL )
    {
      oldToNew[orignalNode]=cloneNode;  //map origunal node to clone node
      orignalNode=orignalNode->next;
      cloneNode=cloneNode->next;
    }


    // step3  :> arrange random pointer
    orignalNode=head;
    cloneNode=cloneHead;
    while (orignalNode!=NULL)
    {
        cloneNode->random=oldToNew[orignalNode->random];  //mapping
        orignalNode=orignalNode->next;
        cloneNode=cloneNode->next;
    }
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
