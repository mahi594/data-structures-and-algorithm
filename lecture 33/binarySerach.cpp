#include<iostream>
using namespace std;

void print(int arr[],int s,int e)
{
    for(int i=s;i<=e;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool binarysearch(int arr[],int s,int e,int key)
{

cout<<endl;
print(arr,s,e);
    //base case

    //element not found
    if(s>e)
    {
        return false;
    }
    int mid=s+(e-s)/2;
    cout<<mid<<endl;

    //element found
    if(arr[mid]==key)
    {
        return true;
    }
    else if(arr[mid]>key)
    {
       binarysearch(arr,s,mid-1,key);
    }
    else
    {
        binarysearch(arr,mid+1,e,key);
    }
}

int main()
{
    int arr[5]={2,4,6,8,10};
    int size=5;
    int key=10;

    cout<<"present or not "<< binarysearch(arr,0,size-1,key);
    
    return 0; 
}