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

void insertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
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

Node* sortedList(Node* head) {
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == 0)
            zeroCount++;
        else if (temp->data == 1)
            oneCount++;
        else if (temp->data == 2)
            twoCount++;
        temp = temp->next;
    }

    temp = head;  //again asign temp to head
    while (temp != NULL) {
        if (zeroCount > 0) {
            temp->data = 0;
            zeroCount--;  // till all the  zeros get on their place 
        } else if (oneCount > 0) {
            temp->data = 1;
            oneCount--;
        } else if (twoCount > 0) {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }

    return head;
}

void print(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(0);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAtHead(head, 1);
    print(head);
    insertAtTail(tail, 2);
    print(head);
    insertAtMiddle(head, tail, 2, 0);
    print(head);
    insertAtHead(head, 0);
    print(head);
    insertAtTail(tail, 1);
    print(head);
    insertAtMiddle(head, tail, 2, 2);
    print(head);

    head = sortedList(head);
    print(head);

    return 0;
}
