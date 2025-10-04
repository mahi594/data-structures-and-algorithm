#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    // Min-heap of size k
    priority_queue<int, vector<int>, greater<int>> mini;

    int n = arr.size();

    // Generate all subarray sums
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if (mini.top() < sum)
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top(); // kth largest sum
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 3;

    int ans = getKthLargest(arr, k);
    cout << k << "rd largest subarray sum = " << ans << endl;

    return 0;
}

//tc=n^2logk
//sc=k