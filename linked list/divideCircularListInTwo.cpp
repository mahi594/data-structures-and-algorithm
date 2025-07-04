#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node " << value << endl;
    }
};

void insertNode(Node*& tail, int element, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    } 
    else {
        Node* current = tail;
        while (current->data != element) {
            current = current->next;
        }
        Node* temp = new Node(d);
        temp->next = current->next;
        current->next = temp;

        // Update tail if we inserted after tail
        if (current == tail) {
            tail = temp;
        }
    }
}

Node* getMiddle(Node* head) {
    if (head == NULL || head->next == head)
        return head;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void divideList(Node* head, Node*& head1, Node*& head2) {
    if (head == NULL || head->next == head) {
        head1 = head;
        head2 = NULL;
        return;
    }

    Node* mid = getMiddle(head);
    Node* second = mid->next;

    // Make first half circular
    mid->next = head;

    // Find tail of second half
    Node* temp = second;
    while (temp->next != head)
        temp = temp->next;

    temp->next = second;

    head1 = head;
    head2 = second;
}

void print(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* tail = NULL;

    // Inserting nodes
    insertNode(tail, 5, 3);   // First node (tail becomes 3)
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 6);
    insertNode(tail, 3, 4);
    insertNode(tail, 5, 7);
    insertNode(tail, 6, 8);
    insertNode(tail, 8, 9);
    insertNode(tail, 3, 2);

    // Getting head
    Node* head = tail->next;

    cout << "Original Circular List: ";
    print(head);

    Node* head1 = NULL;
    Node* head2 = NULL;

    divideList(head, head1, head2);

    cout << "First Half Circular List: ";
    print(head1);

    cout << "Second Half Circular List: ";
    print(head2);

    return 0;
}
