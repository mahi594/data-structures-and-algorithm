#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>&arr,int size)
{
    for(int i=0;i<size-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                 swap(arr[j+1],arr[j]);
                 swapped=true;
            }
        }
        if(swapped==false)   //already sorted
        {
            break;
        }
       
    }
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the elements: ";
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, size);

    cout << "Sorted array: ";
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


