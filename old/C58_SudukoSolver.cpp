#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>> &arr, int row, int col, char dig)
{
    for (int i = 0; i < 9; i++)
    {
        // horizontal
        if (arr[row][i] == dig)
        {
            return false;
        }
        if (arr[i][col] == dig)
        {
            return false;
        }

        /// grid
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for (int i = sr; i <= sr + 2; i++)
        {
            for (int j = sc; j <= sc + 2; j++)
            {
                if (arr[i][j] == dig)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool solveSuduko(vector<vector<char>> &arr, int row, int col)
{
    if (row == 9)
    {
        return true;
    }

    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow++;
        nextCol = 0;
    }

    if (arr[row][col] != '.')
    {
        return solveSuduko(arr, nextRow, nextCol);
    }

    for (char dig = '1'; dig <= '9'; dig++)
    {
        if (isSafe(arr, row, col, dig))
        {
            arr[row][col] = dig;
            if (solveSuduko(arr, nextRow, nextCol))
            {
                return true;
            }
            arr[row][col] = '.';
        }
    }
    return false;
}

int main()
{

    vector<vector<char>> arr = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (solveSuduko(arr, 0, 0))
    {
        for (vector<char> val : arr)
        {
            cout << " | ";
            for (char val1 : val)
            {
                cout << val1 << " ";
            }
            cout << "|" << endl;
        }
    }
    else
    {
        cout << "Not possible with this combination";
    }

    return 0;
}