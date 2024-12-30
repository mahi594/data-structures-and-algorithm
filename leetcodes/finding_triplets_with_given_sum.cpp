#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

vector<vector<int>> tripletSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == s)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end()); // Sorting the triplet
                    ans.push_back(temp);
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n, sum;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the sum: ";
    cin >> sum;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> result = tripletSum(arr, sum);
    cout << "Triplets with the given sum are: " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i][0] << ", " << result[i][1] << ", " << result[i][2] << "]" << endl;
    }

    return 0;
}
