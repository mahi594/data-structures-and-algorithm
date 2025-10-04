#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> printPattern(vector<vector<int>> arr,int n)
{
    int count=2;
    int k=1;
    int i=0,j=0;
    bool turn =false;
    arr[0][0]=1;

    
    for(k=1;k<=2*n-2;k++)
    {
        if(turn==false && k<n)
    {
         for(i=k,j=0;i>=0 && j<=k;i--,j++)
        {
            arr[i][j]=count;
            count++;
        }
        turn=true;
    }
    else if(turn ==true && k<n)
    {
        for(int i=0,j=k;j>=0 && i<=k;i++,j--)
        {
            arr[i][j]=count;
            count++;
        }
        turn=false;
    }
    else if(turn==false && k>=n)
    {
        for(int i=k-n+1,j=n-1;j>=1 && i<n;i++,j--)
        {
            arr[i][j]=count;
            count++;
        }
        turn=true;
    }
    else if(turn==true && k>=n)
    {
        for(int j=k-n+1,i=n-1;i>=1 && j<n;i--,j++)
        {
            arr[i][j]=count;
            count++;
        }
        turn=false;
    }
       
    }
    return arr;
}    




int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n, 0));  
     arr = printPattern(arr,n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}