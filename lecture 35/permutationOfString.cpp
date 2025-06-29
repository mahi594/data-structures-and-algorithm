#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string &s, int index, vector<string> &ans) {
    if (index >= s.length()) {
        ans.push_back(s);
        return;
    }

    for (int j = index; j < s.length(); j++) {
        swap(s[index], s[j]);           // Fix a character at position `index`
        solve(s, index + 1, ans);       // Recurse for next index
        swap(s[index], s[j]);           // Backtrack to original string
    }
}

vector<string> permute(string s) {
    vector<string> ans;
    solve(s, 0, ans);
    return ans;
}

int main() {
    string s = "abc";
    vector<string> result = permute(s);

    cout << "Permutations:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
