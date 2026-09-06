#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Set Matrix Zeroes
// ===============================================================
//
// If an element is 0, set its entire row and column to 0.
//
// Example:
//
// 1  1  1
// 1  0  1
// 1  1  1
//
// becomes:
//
// 1  0  1
// 0  0  0
// 1  0  1
//
// ===============================================================

// ---------------------------------------------------------------
// 1. Brute Force
// ---------------------------------------------------------------
//
// Whenever we find a zero, mark its entire row and column with
// a temporary value.
//
// We cannot directly put 0 because newly created zeroes would
// incorrectly affect other rows and columns.
//
// Here we use -1 as the temporary marker.
//
// This approach works when the matrix contains only non-negative
// values. For the general problem, use a safer marker or the
// better approach below.
//
// Time Complexity : O(n * m * (n + m))
// Space Complexity : O(1)
// ---------------------------------------------------------------

void setZeroesBruteForce(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {

                for (int k = 0; k < m; k++)
                {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
                }

                for (int k = 0; k < n; k++)
                {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

// ---------------------------------------------------------------
// 2. Better
// ---------------------------------------------------------------
//
// Store the rows and columns which contain zero.
//
// Then make those rows and columns zero.
//
// This is exactly the approach used in your solution.
//
// Time Complexity : O(n * m)
// Space Complexity : O(n + m)
// ---------------------------------------------------------------

void setZeroesBetter(vector<vector<int>> &matrix)
{
    set<int> rowS;
    set<int> colS;

    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowS.insert(i);
                colS.insert(j);
            }
        }
    }

    for (int it : rowS)
        for (int i = 0; i < m; i++)
            matrix[it][i] = 0;

    for (int it : colS)
        for (int i = 0; i < n; i++)
            matrix[i][it] = 0;
}

// ---------------------------------------------------------------
// 3. Optimal
// ---------------------------------------------------------------
//
// Use the first row and first column themselves as markers.
//
// matrix[i][0] -> tells whether row i should become zero.
//
// matrix[0][j] -> tells whether column j should become zero.
//
// We separately store whether the first row and first column
// themselves originally contained a zero.
//
// Time Complexity : O(n * m)
// Space Complexity : O(1)
// ---------------------------------------------------------------

void setZeroesOptimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    bool firstRowZero = false;
    bool firstColZero = false;

    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] == 0)
            firstRowZero = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
            firstColZero = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (firstRowZero)
    {
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }

    if (firstColZero)
    {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
}

// ===============================================================
// Print Matrix
// ===============================================================

void printMatrix(vector<vector<int>> &matrix)
{
    for (auto &row : matrix)
    {
        for (int val : row)
            cout << val << " ";

        cout << endl;
    }
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<vector<int>> matrix =
        {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}};

    vector<vector<int>> matrix1 = matrix;
    setZeroesBruteForce(matrix1);

    cout << "Brute Force :" << endl;
    printMatrix(matrix1);

    vector<vector<int>> matrix2 = matrix;
    setZeroesBetter(matrix2);

    cout << "\nBetter :" << endl;
    printMatrix(matrix2);

    vector<vector<int>> matrix3 = matrix;
    setZeroesOptimal(matrix3);

    cout << "\nOptimal :" << endl;
    printMatrix(matrix3);

    return 0;
}