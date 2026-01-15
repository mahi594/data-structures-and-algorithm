#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // key -> list of anagrams
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++)
        {
            int freq[26] = {0};

            // count frequency of characters
            for(char c : strs[i])
            {
                freq[c - 'a']++;
            }

            // convert frequency array to string key
            string key = "";
            for(int j = 0; j < 26; j++)
            {
                key += "#";
                key += to_string(freq[j]);
            }

            mp[key].push_back(strs[i]);
        }

        // extract result
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
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};

    Solution obj;
    vector<vector<string>> result = obj.groupAnagrams(strs);

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
