#include<iostream>
using namespace std;

int  getSum(int  *arr,int n)
{

    cout<<sizeof(arr)<<endl;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    return sum;
}

int main()
{
    int arr[5]={1,2,3,4,5};

    cout<<"sum is " <<getSum(arr,5)<<endl;
    cout<<"sum is " <<getSum(arr+2,5)<<endl;
}