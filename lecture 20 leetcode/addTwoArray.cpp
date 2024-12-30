#include<iostream>
#include<vector>
using namespace std;

vector<int>reverse(vector<int>&v)
{
    int s=0;
    int e=v.size()-1;

    while(s<e)
    {
        swap(v[s++],v[e--]);
    }
    return v;
}

vector<int>FindSumArray(vector<int>&a,int n,vector<int>&b,int m)
{
    int i=n-1;
    int j=m-1;
    int carry=0;

    vector<int>ans;

    while(i>=0&&j>=0)
    {
       int val1=a[i];
       int val2=b[j];

       int sum=val1+val2+carry;
       carry=sum/10;
       sum=sum%10;
       ans.push_back(sum);
       i--;
       j--;
    }

    //first case
     while(i>=0)
    {
       int sum=a[i]+carry;
       carry=sum/10;
       sum=sum%10;
       ans.push_back(sum);
       i--;
    }

    
    //second case
     while(j>=0)
    {
       int sum=b[j]+carry;
       carry=sum/10;
       sum=sum%10;
       ans.push_back(sum);
       j--;
    }

    
    //third case
     while(carry!=0)
    {
       int sum=carry;
       carry=sum/10;
       sum=sum%10;
       ans.push_back(sum);
    }

    reverse(ans);
    return ans;

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
   vector<int> a = {1,2,3,4}; // Represents the number 999
    vector<int> b = {6};       // Represents the number 1

    vector<int> result = FindSumArray(a, a.size(), b, b.size());

    cout << "Sum of the two arrays is: ";
    print(result);

    return 0;
}
