#include <iostream>
#include <vector>
using namespace std;

// Function to rotate the matrix 90 degrees clockwise
void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix (swap rows and columns)
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each column to rotate 90 degrees clockwise
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[j][i], matrix[n - j - 1][i]);
        }
    }
}

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    // Input the size of the matrix (assuming square matrix)
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    // Input the elements of the matrix
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Rotate the matrix by 90 degrees clockwise
    rotateMatrix(matrix);

    // Print the rotated matrix
    cout << "The rotated matrix is:\n";
    printMatrix(matrix);

    return 0;
}
