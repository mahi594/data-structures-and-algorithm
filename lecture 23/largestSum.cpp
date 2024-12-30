#include<iostream>
#include<climits>
using namespace std;



int largestSum(int arr[][4])
{
    int maxi=INT_MIN;
    int rowIndex=-1; 
    for(int i=0;i<3;i++)
    {
        int sum=0;
        for(int j=0;j<4;j++)
        {
           sum=sum +arr[i][j];
        }
        if(sum>maxi)
        {
            maxi=sum;
            rowIndex=i;

        }

    }
    cout<<"the maximum sum is"<<maxi<<endl;
    return rowIndex; 
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

    
    cout<<"maximum row  index is"<<largestSum(arr)<<endl;
    return 0;
}