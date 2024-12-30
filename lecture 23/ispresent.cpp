#include<iostream>
using namespace std;

bool isPresent(int arr[][4],int target,int row,int col  )
    {
        for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==target)
            {
                return 1;
            }
        }

    }
    return 0;
    }

int main()
{
    //row wise
    // int arr[3][4];
    // for(int i=0;i<3;i++)
    // {
    //     for(int j=0;j<4;j++)
    //     {
    //         cin>>arr[i][j];
    //     }

    // }

    

    //column wise
    int arr[3][4];
    for(int j=0;j<4;j++)
    {
        for(int i=0;i<3;i++)
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

    cout<<"element to search"<<endl;
    int target;
    cin>>target;

    if(isPresent(arr,target,3,4))
    {
    cout<<"element found";
    }
    else
    {
         cout<<"not found";
    }

    return 0;
}