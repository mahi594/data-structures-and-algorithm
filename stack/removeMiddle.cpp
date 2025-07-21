#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int>& s) {
    int size = s.size();
    int mid = size / 2;

    stack<int> temp;
    
    // Step 1: Move top elements to temp stack until middle
    for (int i = 0; i < mid; i++) {
        temp.push(s.top());
        s.pop();
    }

    // Step 2: Remove the middle element
    if (!s.empty()) {
        s.pop();  // This is the middle element
    }

    // Step 3: Push elements back from temp to original
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);  // Stack: Top->5 4 3 2 1

    deleteMiddle(s);

    // Print stack after deletion
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
