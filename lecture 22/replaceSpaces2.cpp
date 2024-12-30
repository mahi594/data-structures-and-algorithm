#include<iostream>
#include<string>

using namespace std;

void replaceSpaces(string &str) {
    int spaceCount = 0;
    int n = str.length();

    // Count the number of spaces
    for (int i = 0; i < n; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }

    // Calculate new length of the string
    int newLength = n + 2 * spaceCount;  // Each space adds 2 extra characters
    str.resize(newLength);  // Resize the string to fit the new characters

    // Start replacing from the end
    int j = newLength - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '4';
            str[j--] = '@';
        } else {
            str[j--] = str[i];
        }
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    replaceSpaces(str);
    cout << "Modified string: " << str << endl;
    return 0;
}
