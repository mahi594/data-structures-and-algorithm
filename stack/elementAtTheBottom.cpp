#include <iostream>
#include <stack>
using namespace std;

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    stack<int> temp;

    // Step 1: Pop all elements into temp stack
    while (!myStack.empty()) {
        temp.push(myStack.top());
        myStack.pop();
    }

    // Step 2: Push x at the bottom (now the only element in myStack)
    myStack.push(x);

    // Step 3: Push all elements back from temp
    while (!temp.empty()) {
        myStack.push(temp.top());
        temp.pop();
    }

    return myStack;
}


int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);  // Stack: Top -> 30 20 10

    int x = 5;  // We want to push 5 at the bottom

    stack<int> updated = pushAtBottom(st, x);

    // Output the stack (Top to Bottom)
    while (!updated.empty()) {
        cout << updated.top() << " ";
        updated.pop();
    }

    return 0;
}
