#include<iostream>
#include<vector>
using namespace std;




// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free " << value << endl;
    }
};





// Insert at head
void insertAtHead(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;

    // if list was empty
    if (tail == NULL) {
        tail = temp;
    }
}





// Insert at tail
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    if (tail != NULL) {
        tail->next = temp;
        tail = temp;
    }
}





// Insert at specific position
void insertAtMiddle(Node* &head, Node* &tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}






// Print list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* getMiddle(Node* head)
{
    Node* slow=head;
    Node* fast=head->next;

    while(fast !=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;

}






//reverse
Node* reverse(Node* head)
{
   Node* current =head;
   Node* previous= NULL;
   Node* next=NULL;

   while(current!=NULL)
   {
    next=current->next;
    current->next=previous;
    previous=current;
    current=next;
   }

   return previous;
}







// Check if linked list is palindrome
bool isPalindrome(Node* head) {
    if(head==NULL && head->next==NULL)
    {
        return true;
    }
    //step 1 Find MIddle
    Node* middle= getMiddle(head);
    //step2 reverse list after middle

    Node*temp= middle->next;
    middle->next=reverse(temp);

    //step 3 compare both halves
    Node* head1=head;
    Node* head2=middle->next;
    while(head2!=NULL)
    {
        if(head1->data!=head2->data)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }

    //step 4::::repaet step 2
    temp= middle->next;
    middle->next=reverse(temp);

    return 1;
    
}








// Main function
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 12);
    print(head);

    insertAtTail(tail, 11);
    print(head);

    insertAtMiddle(head, tail, 2, 40);
    print(head);

    if (isPalindrome(head)) {
        cout << "Linked list is a palindrome." << endl;
    } else {
        cout << "Linked list is not a palindrome." << endl;
    }

    return 0;
}
