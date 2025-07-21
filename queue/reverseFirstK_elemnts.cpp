#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        stack<int> s;

        // Step 1: Push first k elements into the stack
        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Enqueue back the stack elements (reversed k elements)
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Move the remaining (n - k) elements to the back to preserve their order
        int t = q.size() - k;  // Remaining elements count
        while (t--) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};

int main() {
    queue<int> q;
    
    // Sample input
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    
    int k = 3;

    Solution sol;
    queue<int> result = sol.reverseFirstK(q, k);

    // Output the modified queue
    cout << "Queue after reversing first " << k << " elements: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }

    cout << endl;
    return 0;
}
