#include <iostream>
#include<vector>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int uniqueOccurrences(int arr[],int size) 
{
    int ans = 0;
    for (int i = 0; i < size; i++) // XOR ing array elements
    {
        ans = ans ^ arr[i];
    }
    for (int i = 0; i <size; i++) // XOR[1,n-1]
    {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{
    int size;
    cout << "size is: ";
    cin >> size;

    int arr[50];

    printArray(arr, size);

    int duplicate = uniqueOccurrences(arr, size);
    cout << "duplicate element is: " << duplicate << endl;

    return 0;
}
