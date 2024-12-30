#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j;
        for(j = i - 1; j >= 0; j--)
        {
            if(arr[j] > temp)  // Corrected condition
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
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

    insertionSort(arr, size);

    cout << "Sorted array: ";
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
