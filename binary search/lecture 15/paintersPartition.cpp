#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int k, int mid)
{
    int painterCount=1;
    int partitionSum=0;
    
    for(int i=0;i<n;i++)
    {
        if(partitionSum+arr[i]<=mid)
        {
            partitionSum= partitionSum+arr[i];
        }

        else
        {
            painterCount++;
            if(painterCount>k||arr[i]>mid)
            {
                return false;
            }
            partitionSum=arr[i];
        }
    }
    return true;
    
}

int paintersPartition(vector<int> &arr, int n, int k)
{
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,k,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main() {
    int n, m;
    
    cout << "Enter the partition size : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the number of partion for each painter: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the number of painters: ";
    cin >> m;

    cout << "The minimum number of pages: " << paintersPartition(arr, n, m) << endl;
    return 0;
}