#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string &s) {
        unordered_map<char, int> count;
        queue<char> q;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // Increase count
            count[ch]++;

            // Push into queue
            q.push(ch);

            // Find the first non-repeating character
            while (!q.empty()) {
                if (count[q.front()] > 1) {
                    q.pop(); // Remove repeating
                } else {
                    ans.push_back(q.front()); // Found non-repeating
                    break;
                }
            }

            // If no non-repeating character is found
            if (q.empty()) {
                ans.push_back('#');
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "aabc";
    cout << sol.FirstNonRepeating(s) << endl; // Output: a#bb
    return 0;
}
