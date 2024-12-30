#include<iostream>
#include<vector>
using namespace std;

void rotateArray(vector<int>& nums,int k)
{
   vector<int>temp(nums.size());
   for(int i=0;i<nums.size();i++)
   {
    temp[(i+k)%nums.size()]=nums[i];
   }
   //copy temp into num vector

   nums=temp;
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
    int k;
    cout<<"from no. yo be rotated"<<" ";
    cin>>k;
    vector<int> v = {11, 12,13,14};

    rotateArray(v,k);

    cout << "Array after rotating: ";
    print(v);

    return 0;
}
