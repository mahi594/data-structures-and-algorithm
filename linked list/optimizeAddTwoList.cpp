#include<iostream>
using namespace std;



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
    if (tail == NULL) {
        tail = temp;
    }
}




// Insert at tail
void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    if (tail != NULL) {
        tail->next = temp;
        tail = temp;
    } else {
        head = temp;
        tail = temp;
    }
}






// Insert at a specific position
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
        insertAtTail(head,tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}





// Find middle of the list
Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}




// Divide list into two halves
void divide(Node* head, Node* &firstHalf, Node* &secondHalf) {
    if (head == NULL || head->next == NULL) {
        firstHalf = head;
        secondHalf = NULL;
        return;
    }

    Node* middle = getMiddle(head);
    firstHalf = head;
    secondHalf = middle->next;
    middle->next = NULL;
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




Node* add(Node*first,Node* second)
{
    Node* anshead=NULL;
    Node* ansTail=NULL;
    int carry=0;


    while(first!=NULL || second!=NULL || carry!=0)
    {

        int val1=0;
        if(first !=NULL)
        {
            val1=first->data;
        }

        int val2=0;
        if(second !=NULL)
        {
            val2=second->data;
        }

       int sum=carry+val1+val2;
       int digit=sum%10;
       Node* temp= new Node(digit);
       //create node and add ans in linked list
       insertAtTail(anshead,ansTail,digit); //digit should be added in the list
       carry=sum/10;
       if(first!=NULL)
       {
         first=first->next;
       }
       if(second!=NULL)
       {
         second=second->next;
       }


    }
    
    return anshead;
}





Node* addTwoList(Node*first,Node* second)
{
    //step1::::>>reverse
    first=reverse(first);
    second=reverse(second);

    //step 2::::::>>>>add them
    Node* ans=add(first,second);

    //step 3::::>>>> reverse ans
    ans=reverse(ans);
 
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

// Main
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 5);
    insertAtTail(head,tail, 6);
    insertAtTail(head,tail, 7);
    insertAtTail(head,tail, 8);
    insertAtTail(head,tail, 9);
    insertAtTail(head,tail, 1);

    cout << "Original List: ";
    print(head);

    Node* firstHalf = NULL;
    Node* secondHalf = NULL;

    divide(head, firstHalf, secondHalf);

    cout << "First Half: ";
    print(firstHalf);

    cout << "Second Half: ";
    print(secondHalf);

    Node* sum= addTwoList(firstHalf,secondHalf);

    print(sum);

    return 0;
}
