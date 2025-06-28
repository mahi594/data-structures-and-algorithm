#include<iostream>
using namespace std;

void reverseString(string &s, int i, int j)  // Pass string by reference
{
    if (i > j) return;  // Base condition

    swap(s[i], s[j]);  // Swap characters
    i++;
    j--;
    reverseString(s, i, j);  // Recursive call
}

int main()
{
    string s = "abcdef";
    reverseString(s, 0, s.length() - 1);  // Pass correct indices
    cout << s << endl;  // Output: fedcba
}
