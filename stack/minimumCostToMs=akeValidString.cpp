#include <bits/stdc++.h> 
using namespace std;

int findMinimumCost(string str)
{
    // Odd length cannot be balanced
    if (str.length() % 2 == 1) {
        return -1;
    }

    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch == '{') {
            s.push(ch);
        }
        else {
            // ch is '}'
            if (!s.empty() && s.top() == '{') {
                s.pop(); // Valid pair
            }
            else {
                s.push(ch); // Unmatched closing brace
            }
        }
    }

    // Now stack contains only unmatched braces
    int a = 0, b = 0;
    while (!s.empty()) {
        if (s.top() == '}') {
            a++;
        }
        else {
            b++;
        }
        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main()
{
    string str;
    cout << "Enter the expression: ";
    cin >> str;

    int result = findMinimumCost(str);
    if (result == -1)
        cout << "Invalid input length (odd), cannot balance." << endl;
    else
        cout << "Minimum cost to balance: " << result << endl;

    return 0;
}
