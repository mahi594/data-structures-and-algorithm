#include <iostream>
using namespace std;


int  partition(int arr[], int s,int e)
{
    int pivot=arr[s];
    int count=0;

    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }


    //place pivot at right position
    int pivotIndex= s+count;
    swap(arr[pivotIndex],arr[s]);  //pivot at its right place

    //left and right part of pivot
    int i=s,j=e;

    while(i<pivotIndex&&j>pivotIndex)
    {
        while(arr[i]<=arr[pivotIndex])
        {
            i++;
        }

        while(arr[pivotIndex]<arr[j])
        {
            j--;
        }

        if(i<pivotIndex&&j>pivotIndex)
        {
            swap(arr[i++],arr[j--]);
        }

    }

    return pivotIndex;


}




void quickSort(int arr[], int s,int e)
{
    

     //base case
     if(s>=e)
     {
        return;
     }

     int p = partition(arr,s,e);
     quickSort(arr,s,p-1);
     quickSort(arr,p+1,e);
}


int main()
{
    int n=5;
    int arr[n]={3,1,4,5,2,3,3,3,2,2,2,2};

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    

}