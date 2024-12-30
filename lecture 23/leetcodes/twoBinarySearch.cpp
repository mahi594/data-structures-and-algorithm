#include<iostream>
#include<vector>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix,int target)
{
    int row=matrix.size();
    int col=matrix[0].size();

    int rowINdex=0;
    int colIndex=col-1;

    while(rowINdex<row && colIndex>=0)
    {
        int element=matrix[rowINdex][colIndex];

        if(element==target)
        {
            return 1;
        }
        if(element<target)
        {
            rowINdex++;
        }
        else{
            colIndex--;
        }
        return 0;
    }         
}
int main() {
    int rows, cols, target;

    // Input the size of the matrix
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    // Input the elements of the matrix
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Input the target element to search for
    cout << "Enter the target element: ";
    cin >> target;

    // Search for the target in the matrix
    if (searchMatrix(matrix, target)) {
        cout << "Element " << target << " is found in the matrix.\n";
    } else {
        cout << "Element " << target << " is not found in the matrix.\n";
    }

    return 0;
}

