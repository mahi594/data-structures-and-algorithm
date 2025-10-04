#include<iostream>
#include<queue>
using namespace std;

int kthSmallest(int arr[],int l,int r,int k)
{
    priority_queue<int>pq;

    //1:>max heap of first k elements
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }

    //2:>
    for(int i=k;i<=r;i++)
    {
        if(arr[i]<pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //ans=pq.top()
    int ans= pq.top();
    return ans;

}

int main()
{
    int arr[6]={7,10,4,3,20,15};

    int ans= kthSmallest(arr,0,5,4);
    cout<<ans<<endl;

}