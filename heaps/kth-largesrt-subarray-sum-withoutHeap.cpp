#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    vector<int> sumStore;
    int n = arr.size();

    // Generate all subarray sums
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    // Sort sums in ascending order
    sort(sumStore.begin(), sumStore.end());

    // k-th largest = element at (size - k)
    return sumStore[sumStore.size() - k];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 3;

    int ans = getKthLargest(arr, k);
    cout << k << "rd largest subarray sum = " << ans << endl;

    return 0;
}
