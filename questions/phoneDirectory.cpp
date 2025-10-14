#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode('\0');
    }

    // Recursive function to insert a word
    void insertUtil(TrieNode *root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->countChild++;
        }

        insertUtil(child, word.substr(1));
    }

    // Insert a word after converting to lowercase
    void insertWord(string word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        insertUtil(root, word);
    }

    // Recursively gather all words with given prefix
    void printSuggestion(TrieNode *curr, vector<string> &temp, string prefix) {
        if (curr->isTerminal)
            temp.push_back(prefix);
            

        for (char ch = 'a'; ch <= 'z'; ch++) 
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();  //backtracking
            }
        }
    }

    // Return all suggestions for each prefix of the query
    vector<vector<string>> getSuggestion(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];
            prefix.push_back(lastch);

            TrieNode *curr = prev->children[lastch - 'a'];
            if (curr == NULL)
                break;

            vector<string> temp;
            printSuggestion(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }

        return output;
    }
};

// Function that inserts contacts and returns suggestions
vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr) {
    Trie *t = new Trie();

    for (int i = 0; i < contactList.size(); i++)
        t->insertWord(contactList[i]);

    return t->getSuggestion(queryStr);
}

// ---------- MAIN FUNCTION ----------
int main() {
    vector<string> contactList = {"cod", "codding", "coding","coely"};
    string queryStr = "coding";

    vector<vector<string>> result = phoneDirectory(contactList, queryStr);

    cout << "Phone Directory Suggestions:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Suggestions for prefix \"" << queryStr.substr(0, i + 1) << "\": ";
        if (result[i].empty()) {
            cout << "No match found";
        } else {
            for (string s : result[i])
                cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
