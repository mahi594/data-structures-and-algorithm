#include<iostream>
using namespace std;

void mergeSortedArray(int arr1[], int n, int arr2[], int m)
{
    int i = n - 1;  // Last element index of the initial elements in arr1
    int j = m - 1;  // Last element index of arr2
    int k = n + m - 1;  // Last position in arr1 where elements will be placed

    // Merge arr2 into arr1 starting from the end
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i];
            i--;
        }
        else
        {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements from arr2 (if any)
    while (j >= 0)
    {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[6] = {1, 4, 6, 0, 0, 0};  // Initial arr1 with space for arr2
    int arr2[3] = {2, 3, 5};  // arr2 to be merged

    mergeSortedArray(arr1, 3, arr2, 3);

    print(arr1, 6);  // Print the merged arr1

    return 0;
}
