#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    queue<int> reverseQueue(queue<int>& q) {
        stack<int> s;

        // Push elements from queue to stack
        while (!q.empty()) {
            int element = q.front();
            q.pop();
            s.push(element);
        }

        // Push elements back from stack to queue
        while (!s.empty()) {
            int element = s.top();
            s.pop();
            q.push(element);
        }

        return q;
    }
};

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original Queue: ";
    queue<int> temp = q;  // Copy to print without modifying
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    Solution sol;
    queue<int> reversed = sol.reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!reversed.empty()) {
        cout << reversed.front() << " ";
        reversed.pop();
    }
    cout << endl;

    return 0;
}
