#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& num)
{
    int count = 0;
    int n = num.size();

    for(int i = 1; i < n; i++)  // Start from 1 to avoid out-of-bounds error
    {
        if(num[i-1] > num[i])
        {
            count++;
        }
    }

    if(num[n-1] > num[0])  // To check if the array is rotated and sorted
    {
        count++;
    }

    return count <= 1;  // Return true if count is 1 or less
}

void print(const vector<int>& v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 4, 5, 1, 2};
    vector<int> v3 = {3, 5, 7, 6, 1};

    cout << "Check for v1: " << check(v1) << endl;
    cout << "Check for v2: " << check(v2) << endl;
    cout << "Check for v3: " << check(v3) << endl;

    return 0;
}
