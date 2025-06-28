#include<iostream>
using namespace std;

int print(int arr[],int size)
{
    cout<<"size is "<<size<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
            }
}
bool search(int arr[],int size,int key)
{
    print(arr,size);
    //base case
    if(size==0)
    { 
        return false;

    }
    if(arr[0]==key)
    {
        return true;

    }
    else{ 
    int remainingpart=search(arr+1,size-1,key);
    
    return remainingpart;
    }
}

int main()
{
    int arr[5]={3,5,1,2,4};
    int size=5;
    int key=6;
    bool ans= search(arr,size,key);
    if(ans){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    return 0; 
}