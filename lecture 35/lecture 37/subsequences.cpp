#include<iostream>
#include<vector>
using namespace std;


class Solution {
    private:
    void solve(string& input,string output,int index,vector<string>& ans)
    {
        if(index>=input.size())  //base case
        {
            ans.push_back(output); //before returnoing we have to store the output
            //this push back will take O(n) complexity
            return;
        }

        //For each element, you have two choices: include or exclude

//So, total subsets = 2^n (like a binary tree with depth n)

        //exclude
        solve(input,output,index+1,ans);     //increment i by 1

        //include
        char element=input[index];
        output.push_back(element);
        solve(input,output,index+1,ans);
    }
public:
    vector<string> subsets(string input)
     {
        vector<string> ans;   //all the answers are stored here
        string output="";    //this will give the outputs which will be stored in ans
        int index=0;
        solve(input,output,index,ans);
        return ans;
        
    }
};

int main() {
    Solution sol;

    string input = "abc";
    vector<string> result = sol.subsets(input);

    cout << "All subsets are:\n";
    for (const string& subset : result) {
        cout << "\"" << subset << "\"" << endl;
    }

    return 0;
}