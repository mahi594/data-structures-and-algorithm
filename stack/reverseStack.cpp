#include <iostream>
#include <stack>
using namespace std;

// Insert an element at the bottom of the stack
void insertAtBottom(stack<int> &stack, int value) {
    // Base case
    if (stack.empty()) {
        stack.push(value);
        return;
    }

    int num = stack.top();
    stack.pop();

    // Recursive call
    insertAtBottom(stack, value);

    stack.push(num);
}

// Reverse the entire stack
void reverseStack(stack<int> &stack) {
    // Base case
    if (stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    // Recursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}

// Test the reverseStack function
int main() {
    stack<int> st;

    // Push elements into the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);  // Stack top -> 4 3 2 1

    cout << "Original Stack (top to bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the stack
    reverseStack(st);

    // Print the reversed stack
    cout << "Reversed Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
