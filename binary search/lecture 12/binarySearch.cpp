#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    // int mid=(start+end)/2;
    
    int mid=start+(end-start)/2;

    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        if(key>arr[mid])
       {
        start=mid+1;

       }
       else{
        end=mid-1;
       }
    //    mid=(start+end)/2;

        mid=start+(end-start)/2;
    }
    return -1;
}

int main()
    {
        int even[6]={1,3,5,6,7,9};
        int odd[7]={2,3,4,5,6,7,8};

        int evenIndex= binarySearch(even,6,3);
        cout<<"index is in even array"<<evenIndex<<endl;
        int oddIndex= binarySearch(odd,7,7);
        cout<<"index is in odd array"<<oddIndex<<endl;
        
    }