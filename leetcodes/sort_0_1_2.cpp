#include <iostream>
using namespace std;

void inputArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}

// void sortArray(int arr[], int size)
// {
//     int low = 0;
//     int mid = 0;
//     int high = size - 1;

//     while (mid <= high)
//     {
//         switch (arr[mid])
//         {
//         case 0:
//             swap(arr[low], arr[mid]);
//             low++;
//             mid++;
//             break;
//         case 1:
//             mid++;
//             break;
//         case 2:
//             swap(arr[mid], arr[high]);
//             high--;
//             break;
//         }
//     }
// }

#include <iostream>
using namespace std;

void inputArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}

void sortArray(int arr[], int size)
{
    int low = 0;    // Pointer for the next position of 0
    int mid = 0;    // Pointer for the current element
    int high = size - 1; // Pointer for the next position of 2

    while (mid <= high)
    {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]); // Place 0 at the beginning
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++; // 1 is already in place, just move mid pointer
        } else { // arr[mid] == 2
            swap(arr[mid], arr[high]); // Place 2 at the end
            high--;
        }
    }
}

void finalPrintArray(int arr[], int size)
{
    cout << "Final array after sorting is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array: ";
    inputArray(arr, size);
    sortArray(arr, size);
    finalPrintArray(arr, size);

    return 0;
}


void finalPrintArray(int arr[], int size)
{
    cout << "Final array after sorting is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array: ";
    inputArray(arr, size);
    sortArray(arr, size);
    finalPrintArray(arr, size);

    return 0;
}
