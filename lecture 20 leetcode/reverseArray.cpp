#include<iostream>
#include<vector>
using namespace std;

vector<int>reverse( vector<int>v,int m)
{
    int s=m+1;   //reverse after m
    int e=v.size()-1;

    while(s<=e)
    {
        swap(v[s],v[e]);
        s++;
        e--;
    }

    return v;
}

void print(vector<int>v,int m)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }   
}

int main()
{
    int m;
    cout<<"from the no. array is to reverse"<<" ";    //reverse after m
    cin>>m;
    vector<int>v;

    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);

    vector<int>ans=reverse(v,m);
      
    cout<<"reverse array is"<<" ";
    print(ans,m);

    return 0;
}