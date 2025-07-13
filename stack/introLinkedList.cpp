#include<iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek operation
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool empty() {
        return top == NULL;
    }

    // Display all elements
    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to test
int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element is: " << st.peek() << endl;

    st.pop();

    cout << "After popping, top is: " << st.peek() << endl;

    cout << "Current stack: ";
    st.display();

    return 0;
}
