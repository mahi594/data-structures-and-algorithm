#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>&matrix)
{
    vector<int>ans;

    //length of matrix
    int row=matrix.size(); 
    int col= matrix[0].size();


    int count=0;   //to count
    int total=row*col;   //to find the total no of elements


    //index intialization
    int startRow=0;
    int startCol=0;
    int endRow=row-1;
    int endCol=col-1;


    while(count<total)
    {
        //print starting row
        for(int index=startCol;count<total && index<=endCol;index++)
        {
            ans.push_back(matrix[startRow][index]);
            count++;
        }
        startRow++;

        //print end column
        for(int index=startRow;count<total && index<=endRow;index++)
        {
            ans.push_back(matrix[index][endCol]);
            count++;
        }
        endCol--;

        //print end row
        for(int index=endCol;count<total && index>=startCol;index--)
        {
            ans.push_back(matrix[endRow][index]);
            count++;
        }
        endRow--;

        //print start column
        for(int index=endRow;count<total && index>=startRow;index--)
        {
            ans.push_back(matrix[index][startCol]);
            count++;
        }
        startCol++;
    }
    return ans;

}

int main() {
    int nRows, mCol;

    cout << "Enter the number of rows: ";
    cin >> nRows;
    cout << "Enter the number of columns: ";
    cin >> mCol;

    vector<vector<int>> matrix(nRows, vector<int>(mCol));

    cout << "Enter the elements of the matrix row by row:\n";
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < mCol; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);

    cout << "The spiral order is: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}