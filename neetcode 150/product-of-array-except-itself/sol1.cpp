#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> product(n, 1);  // initialize with size n and value 1

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    product[i] = product[i] * nums[j];
                }
            }
        }
        return product;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.productExceptSelf(nums);

    cout << "Product Except Self: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
