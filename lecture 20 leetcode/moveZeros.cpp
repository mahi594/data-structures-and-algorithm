#include<iostream>
#include<vector>
using namespace std;

void moveZeros(vector<int>& nums)
{
    int i = 0;
    for(int j = 0; j < nums.size(); j++)
    {
        if(nums[j] != 0)
        {
            swap(nums[j], nums[i]);
            i++;
        }
    }
}

void print(const vector<int>& v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {11, 0, 12, 0, 13, 14, 0, 15};

    moveZeros(v);

    cout << "Array after moving zeros is: ";
    print(v);

    return 0;
}
