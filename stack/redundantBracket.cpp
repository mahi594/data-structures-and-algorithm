#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            bool isRedundant = true;

            while (!st.empty() && st.top() != '(')
            {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    isRedundant = false;
                }
                st.pop();
            }

            if (!st.empty()) st.pop(); // pop the '('

            if (isRedundant)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    string expression;
    cout << "Enter expression: ";
    cin >> expression;

    if (findRedundantBrackets(expression))
    {
        cout << "Redundant brackets found." << endl;
    }
    else
    {
        cout << "No redundant brackets." << endl;
    }

    return 0;
}
