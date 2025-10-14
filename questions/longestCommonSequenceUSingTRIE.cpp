#include <iostream>
#include <vector>
using namespace std;

// Trie Node class
class TrieNode {
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int countChild;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        countChild = 0;
    }
};

// Trie class
class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode('\0');
    }

    // Recursive utility to insert a word into the Trie
    void insertUtil(TrieNode *root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // If child already exists
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // Create new child
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->countChild++;
        }

        // Recursive call
        insertUtil(child, word.substr(1));
    }

    // Function to insert a word
    void insertWord(string word) { 
        insertUtil(root, word);
    }

    // Function to find LCP from Trie
    void lcp(string str, string &ans) {
        TrieNode *temp = root;

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            // Continue only if single child exists and not terminal
            if (temp->countChild == 1 && !temp->isTerminal) {
                ans.push_back(ch);
                int index = ch - 'a';
                temp = temp->children[index];
            } else {
                break;
            }
        }
    }
};

// Function to get longest common prefix
string longestCommonPrefix(vector<string> &arr, int n) {
    Trie *t = new Trie();

    // Insert all words into Trie
    for (int i = 0; i < n; i++) {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);

    return ans;
}

// Main function
int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string result = longestCommonPrefix(arr, n);

    if (result.length() > 0)
        cout << "Longest Common Prefix: " << result << endl;
    else
        cout << "No common prefix found." << endl;

    return 0;
}
