#include <iostream>
using namespace std;

// Function to count the occurrences of a value in the array
int countOccurrences(int arr[], int size, int value)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            count++;
        }
    }
    return count;
}

bool uniqueOccurrences(int arr[], int size)
{
    int counts[1000] = {0}; // To store counts of occurrences, assuming max size is 1000 for simplicity
    int numCounts = 0;      // To keep track of the number of unique counts we have

    // Count the occurrences of each element and store in counts array
    for (int i = 0; i < size; i++)
    {
        bool alreadyCounted = false;

        // Check if the element is already counted
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                alreadyCounted = true;
                break;
            }
        }

        if (!alreadyCounted)
        {
            counts[numCounts] = countOccurrences(arr, size, arr[i]);
            numCounts++;
        }
    }

    // Check if all counts are unique
    for (int i = 0; i < numCounts; i++)
    {
        for (int j = i + 1; j < numCounts; j++)
        {
            if (counts[i] == counts[j])
            {
                return false; // Found a duplicate count
            }
        }
    }

    return true; // All counts are unique
}

int main()
{
    int arr[] = {1, 2, 2, 1, 1, 3}; // Example input
    int size = sizeof(arr) / sizeof(arr[0]);

    bool result = uniqueOccurrences(arr, size);
    cout << (result ? "true" : "false") << endl; // Output: true

    return 0;
}
