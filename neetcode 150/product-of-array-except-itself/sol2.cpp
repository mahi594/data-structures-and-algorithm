#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        // Prefix multiplication
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Suffix multiplication
        for(int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        vector<int> result(n, 1);

        // Final result
        for(int i = 0; i < n; i++)
        {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {1, 2, 3, 4};

    vector<int> ans = s.productExceptSelf(nums);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
