#include<iostream>
#include<vector>
using namespace std;


class Solution {
    private:
    void solve(vector<int>& nums,vector<int> output,int index,vector<vector<int>>& ans)
    {
        if(index>=nums.size())  //base case
        {
            ans.push_back(output); //before returnoing we have to store the output
            //this push back will take O(n) complexity
            return;
        }

        //For each element, you have two choices: include or exclude

//So, total subsets = 2^n (like a binary tree with depth n)

        //exclude
        solve(nums,output,index+1,ans);     //increment i by 1

        //include
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums)
     {
        vector<vector<int>>ans;   //all the answers are stored here
        vector<int> output;    //this will give the outputs which will be stored in ans
        int index=0;
        solve(nums,output,index,ans);
        return ans;
        
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};  // Example input
    vector<vector<int>> result = sol.subsets(nums);

    // Printing all subsets
    cout << "All subsets are:\n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
