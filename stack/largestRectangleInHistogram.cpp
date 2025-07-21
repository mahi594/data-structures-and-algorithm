#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    { 
        while (s.top() != -1 && arr[s.top()] >= arr[i])   //here s.top() represents the index
        {
            s.pop();
        }

        ans[i] = s.top();   //getting the elemnts of nstack
        s.push(i);    //getting the indexes of array
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangle(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int height = heights[i];

        // if no smaller element to the right, take boundary as n
        if (next[i] == -1)
            next[i] = n;

        int width = next[i] - prev[i] - 1;

        int newArea = height * width;
        area = max(area, newArea);
    }

    return area;
}

int main()
{
    int n;
    cout << "Enter number of bars in histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    int maxArea = largestRectangle(heights);
    cout << "Largest Rectangle Area: " << maxArea << endl;

    return 0;
}
