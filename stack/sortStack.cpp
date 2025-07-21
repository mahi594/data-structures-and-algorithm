#include <bits/stdc++.h>
using namespace std;

// Insert element into sorted stack
void sortedInsert(stack<int> &stack, int num) {
    if (stack.empty() || stack.top() < num) {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    sortedInsert(stack, num);

    stack.push(n);
}

// Sort the stack and return it
stack<int> sortStack(stack<int> &stack) {
    if (stack.empty()) {
        return stack;  // ✅ base case returns the (empty) stack
    }

    int num = stack.top();
    stack.pop();

    // recursive sort
    stack = sortStack(stack);

    sortedInsert(stack, num);  // insert current element in sorted order

    return stack;  // ✅ return the final sorted stack
}


int main() {
    stack<int> st;
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);

    st = sortStack(st);  // get the sorted stack

    cout << "Sorted stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
