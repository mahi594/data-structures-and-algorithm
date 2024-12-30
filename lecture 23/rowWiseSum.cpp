#include<iostream>
using namespace std;

int sum(int arr[][4])
{
    for(int i=0;i<3;i++)
    {
        int sum=0;
        for(int j=0;j<4;j++)
        {
           sum=sum +arr[i][j];
        }
        cout<<sum<<" ";

    }
    cout<<endl; 

}

int main()
{
    
    int arr[3][4];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }

    }


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl; 
    }

    
    sum(arr);
    return 0;
}