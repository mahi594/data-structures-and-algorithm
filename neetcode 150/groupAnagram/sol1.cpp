#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // map: sorted string -> list of original strings
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];          // copy string
            sort(key.begin(), key.end());  // sort characters
            mp[key].push_back(strs[i]);    // store original string
        }

        // extract grouped anagrams
        vector<vector<string>> ans;
        for(auto it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{
    // input
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};

    Solution obj;
    vector<vector<string>> result = obj.groupAnagrams(strs);

    // output
    cout << "Grouped Anagrams:\n";
    for(int i = 0; i < result.size(); i++)
    {
        cout << "[ ";
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "]\n";
    }

    return 0;
}
