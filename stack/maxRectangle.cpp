#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

#define MAX 100  // you can change this as per your input size

vector<int> nextSmallerElement(int* arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
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

vector<int> prevSmallerElement(int* arr, int n)
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

int largestRectangle(int* heights, int n)
{
    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int height = heights[i];
        if (next[i] == -1)
            next[i] = n;

        int width = next[i] - prev[i] - 1;
        int newArea = height * width;
        area = max(area, newArea);
    }

    return area;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    // Compute area for first row
    int area = largestRectangle(M[0], m);

    // Process remaining rows
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
            {
                M[i][j] += M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }

        // Entire row is updated, calculate area
        area = max(area, largestRectangle(M[i], m));
    }

    return area;
}

// 🔸 MAIN function
int main()
{
    int M[MAX][MAX] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    int n = 4, m = 4;

    cout << "Maximum area of rectangle is: " << maxArea(M, n, m) << endl;

    return 0;
}
