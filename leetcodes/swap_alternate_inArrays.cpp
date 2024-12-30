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

int swap_alternate(int arr[], int size)
{
    for (int i = 0; i < size; i = i + 2)
    {
        int temp;

        if ((i + 1) < size)
        {
            // swap(arr[i], arr[i + 1]);

            temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int size;
    cout << "size is" << " ";
    cin >> size;

    int arr[50];

    printArray(arr, size);

    swap_alternate(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}