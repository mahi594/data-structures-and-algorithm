#include<iostream>
#include<vector>
#include<algorithm> // For min and max functions
using namespace std;

vector<vector<int>> pairSum(vector<int>& arr, int s) {
    vector<vector<int>> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == s) {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

int main() {
    int n, sum;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the sum: ";
    cin >> sum;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<vector<int>> result = pairSum(arr, sum);
    cout << "Pairs with the given sum are: " << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]" << endl;
    }
    
    return 0;
}
