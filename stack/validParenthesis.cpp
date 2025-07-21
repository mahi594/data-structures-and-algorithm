#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If opening bracket, push
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            // If closing bracket
            else {
                if (!st.empty()) {
                    char top = st.top();
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;  // closing bracket without matching open
                }
            }
        }

        return st.empty();  // stack should be empty if all matched
    }
};

int main() {
    Solution sol;

    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    cout << test1 << ": " << sol.isValid(test1) << endl;
    cout << test2 << ": " << sol.isValid(test2) << endl;
    cout << test3 << ": " << sol.isValid(test3) << endl;
    cout << test4 << ": " << sol.isValid(test4) << endl;
    cout << test5 << ": " << sol.isValid(test5) << endl;

    return 0;
}
