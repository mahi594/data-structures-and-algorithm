#include <bits/stdc++.h>
using namespace std;

// Function to check whether it's safe to place a value in a given cell
bool isSafe(int row, int col, vector<vector<int>>& board, int value)
{
    for (int i = 0; i < 9; i++)
    {
        // Row check
        if (board[row][i] == value)
            return false;

        // Column check
        if (board[i][col] == value)
            return false;

        // 3x3 subgrid check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
            return false;
    }
    return true;
}

// Recursive function to solve Sudoku
bool solve(vector<vector<int>>& board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            // If the cell is empty
            if (board[row][col] == 0)
            {
                // Try all numbers 1–9
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;  // Place the value

                        // Recursive call to check further
                        if (solve(board))
                            return true;

                        // Backtrack
                        board[row][col] = 0;
                    }
                }
                // No valid value found → backtrack
                return false;
            }
        }
    }
    // All cells filled → solved
    return true;
}

// Wrapper function
void solveSudoku(vector<vector<int>>& sudoku)
{
    solve(sudoku);
}

// Function to print Sudoku board
void printBoard(const vector<vector<int>>& board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> sudoku(9, vector<int>(9));

    cout << "Enter the Sudoku puzzle (9x9) with 0 for empty cells:\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }

    if (solve(sudoku))
    {
        cout << "\nSolved Sudoku:\n";
        printBoard(sudoku);
    }
    else
    {
        cout << "\nNo solution exists for the given Sudoku.\n";
    }

    return 0;
}
