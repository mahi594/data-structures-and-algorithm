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
    cout << "memory is free " << data << endl;
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

void populate(Node*& tail, Node* current) {
    current->next = NULL;  // disconnect current node
    tail->next = current;
    tail = current;
}

Node* sortedList(Node* head) {
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* temp = head;

    // Create separate lists
    while (temp != NULL) {
        Node* nextNode = temp->next;  // store next before breaking the link
        if (temp->data == 0) {
            populate(zerotail, temp);
        } else if (temp->data == 1) {
            populate(onetail, temp);
        } else if (temp->data == 2) {
            populate(twotail, temp);
        }
        temp = nextNode;
    }

    // Merge lists
    if (onehead->next != NULL) {
        zerotail->next = onehead->next;
    } else {
        zerotail->next = twohead->next;
    }

    onetail->next = twohead->next;
    twotail->next = NULL;

    // setup head
    head = zerohead->next;

    // delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

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
