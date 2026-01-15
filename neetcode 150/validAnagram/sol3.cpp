#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, int> mp;

    for (char c : s)
        mp[c]++;

    for (char c : t)
    {
        mp[c]--;
        if (mp[c] < 0)
            return false;
    }

    return true;
}

int main()
{
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t))
        cout << "Valid Anagram";
    else
        cout << "Not an Anagram";

    return 0;
}
