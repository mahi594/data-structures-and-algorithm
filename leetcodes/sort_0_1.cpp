#include <iostream>
using namespace std;

int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}

int sortArray(int arr[],int size)
{
    int i=0;
    int j=size-1;
    while(i<j)
    {
        while(arr[i]==0&&i<j)
        {
            i++;
        }
         while(arr[j]==1&&i<j)
        {
            j--;
        }
        if(arr[i]==1&&arr[j]==0&&i<j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
}

int final_printArray(int arr[], int size)
{    cout<<"final array after sorting is"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<< arr[i];
    }
    cout << endl;
}

int main()
{
    int size;
    cout<<"size is"<<endl;
    cin>>size;

    int arr[50];

    printArray(arr,size);
    sortArray(arr,size);
    final_printArray(arr,size);
}

