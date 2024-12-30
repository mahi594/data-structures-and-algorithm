#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(const vector<vector<int>>& arr, int nRows, int mCol) {
    vector<int> ans;
    for(int col = 0; col < mCol; col++) {
        // even index columns
        if(col % 2 == 0) {
            for(int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
        // Odd index columns (bottom to top)
        else {
            for(int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        }
        cout<<endl;
    }
    return ans; 
}

int main() {
    int nRows, mCol;
    
    cout << "Enter the number of rows: ";
    cin >> nRows;
    cout << "Enter the number of columns: ";
    cin >> mCol;

    vector<vector<int>> arr(nRows, vector<int>(mCol));

    cout << "Enter the elements of the 2D array row by row:\n";
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < mCol; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> result = wavePrint(arr, nRows, mCol);

    cout << "The result is: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
