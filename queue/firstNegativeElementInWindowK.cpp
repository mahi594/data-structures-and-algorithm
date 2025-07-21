#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> firstNegInt(vector<int>& arr, int k) {
    deque<int> dq;
    int size = arr.size();
    vector<int> ans;

    // Process first window of size k
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);  // Store index of negative number
        }
    }

    // Store answer for first window
    if (!dq.empty()) {
        ans.push_back(arr[dq.front()]);
    } else {
        ans.push_back(0);
    }

    // Process the remaining windows
    for (int i = k; i < size; i++) {
        // Remove indices that are out of the current window
        if (!dq.empty() && i - dq.front() >= k) {
            dq.pop_front();
        }

        // Add current index if it's negative
        if (arr[i] < 0) {
            dq.push_back(i);
        }

        // Store result for the current window
        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> result = firstNegInt(arr, k);

    cout << "First negative number in every window of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
