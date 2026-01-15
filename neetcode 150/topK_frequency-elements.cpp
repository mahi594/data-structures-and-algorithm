#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // Step 1: Count frequency
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        // Step 2: Move map to vector of pairs (frequency, number)
        vector<pair<int,int>> v;
        for(auto it : mp)
        {
            v.push_back({it.second, it.first});
        }

        // Step 3: Sort in descending order of frequency
        sort(v.rbegin(), v.rend());

        // Step 4: Take top k elements
        vector<int> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};

int main()
{
    // Example input
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    Solution obj;
    vector<int> result = obj.topKFrequent(nums, k);

    // Output
    cout << "Top " << k << " frequent elements: ";
    for(int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
