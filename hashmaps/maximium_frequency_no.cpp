#include <iostream>
#include <unordered_map>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> m;
    
    int maxfreq = 0;
    int maxAns = 0;

    // Count frequency and find max frequency
    for (int i = 0; i < arr.size(); i++)
    {
        m[arr[i]]++;
        maxfreq = max(maxfreq, m[arr[i]]);
    }

    // Find first element with max frequency
    for (int i = 0; i < n; i++)
    {
        if (maxfreq == m[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1,3};
    int n = arr.size();

    cout << "Element with maximum frequency: " << maximumFrequency(arr, n) << endl;

    return 0;
}
