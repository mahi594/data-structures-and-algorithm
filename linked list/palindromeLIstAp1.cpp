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

// Check if vector is palindrome
bool checkPalindrome(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e) {
        if (arr[s] != arr[e]) {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

// Check if linked list is palindrome
bool isPalindrome(Node* head) {
    vector<int> arr;
    Node* temp = head;
    while (temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(arr);
}

// Main function
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 12);
    print(head);

    insertAtTail(tail, 12);
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
