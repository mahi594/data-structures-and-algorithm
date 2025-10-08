#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to compare heap sizes
int signum(int a, int b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}

// Function to balance heaps and calculate median
void callMedian(int element, priority_queue<int> &maxheap,
                priority_queue<int, vector<int>, greater<int>> &minheap,
                int &median)
{
    switch (signum(maxheap.size(), minheap.size()))
    {
    // Case 1: both heaps equal in size
    case 0:
        if (element > median)
        {
            minheap.push(element);
            median = minheap.top();
        }
        else
        {
            maxheap.push(element);
            median = maxheap.top();
        }
        break;

    // Case 2: maxheap has more elements
    case 1:
        if (element > median)
        {
            minheap.push(element);
            median = (minheap.top() + maxheap.top()) / 2;
        }
        else
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(element);
            median = (minheap.top() + maxheap.top()) / 2;
        }
        break;

    // Case 3: minheap has more elements
    case -1:
        if (element > median)
        {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(element);
            median = (minheap.top() + maxheap.top()) / 2;
        }
        else
        {
            maxheap.push(element);
            median = (minheap.top() + maxheap.top()) / 2;
        }
        break;
    }
}

// Function to find running medians
vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> ans;

    priority_queue<int> maxheap; // Left half
    priority_queue<int, vector<int>, greater<int>> minheap; // Right half
    int median = 0;

    for (int i = 0; i < n; i++)
    {
        callMedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 15, 1, 3};
    int n = arr.size();

    vector<int> result = findMedian(arr, n);

    cout << "Medians: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
