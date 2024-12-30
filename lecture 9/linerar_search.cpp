#include <iostream>
using namespace std;

bool search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return 1;
    }
    return 0;
}

int main()
{
    int array[11] = {2, 4, 6, 8, 7, 9, 1, 3, 5, 11, 10};

    cout << "enter no. to search" << endl;
    int key;
    cin >> key;

    bool found = search(array, 11, key);

    if (found)
    {
        cout << "key is found" << endl;
    }
    else
    {
        cout << "key is not found" << endl;
    }
}