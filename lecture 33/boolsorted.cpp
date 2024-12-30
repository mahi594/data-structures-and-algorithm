#include<iostream>
using namespace std;

bool issorted(int arr[],int size)
{
    //base case
    if(size==0||size==1)
    {
        return true;

    }
    if(arr[0]>arr[1])
    {
        return false;
    }
    else{
        bool remainingPart= issorted(arr+1,size-1);
    }
}

int main()
{
    int arr[5]={2,4,6,8,10};
    int size=5;
    bool ans= issorted(arr,size);
    if(ans)
    {
        cout<<"yes! sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }
}