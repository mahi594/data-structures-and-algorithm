#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";

    // Traverse characters of first string
    for(int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool match = true;

        // Compare this character with all other strings
        for(int j = 1; j < n; j++)
        {
            // If index exceeds string length or characters mismatch
            if(i >= arr[j].length() || arr[j][i] != ch)
            {
                match = false;
                break;
            }
        }

        // If mismatch found, break
        if(!match)
            break;
        else
            ans.push_back(ch);
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter strings:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    string result = longestCommonPrefix(arr, n);

    if(result.length() > 0)
        cout << "Longest Common Prefix: " << result << endl;
    else
        cout << "No common prefix found." << endl;

    return 0;
}
4