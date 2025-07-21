#include<iostream>
#include<stack>
using namespace std;

// Recursive function to delete the middle element
void solve(stack<int>& s, int count, int size)
{
    if(count == size / 2)
    {
        s.pop();  // Remove the middle element
        return;
    }

    int num = s.top();
    s.pop();

    // Recursive call
    solve(s, count + 1, size);

    // Push the popped elements back (except the middle)
    s.push(num);
}

// Helper function to call solve
void deleteMiddle(stack<int>& s, int size)
{
    int count = 0;
    solve(s, count, size);
}

// Test
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);  // Stack: Top->5 4 3 2 1

    deleteMiddle(s, s.size());

    // Print stack after deletion
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
