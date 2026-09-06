#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Rotate Matrix by 90 Degrees Clockwise
// ===============================================================
//
// Example:
//
// 1 2 3          7 4 1
// 4 5 6    ->    8 5 2
// 7 8 9          9 6 3
//
// ===============================================================

// ---------------------------------------------------------------
// 1. Brute Force
// ---------------------------------------------------------------
//
// Create a separate matrix.
//
// For every element:
//
// matrix[i][j] -> ans[j][n-i-1]
//
// Time Complexity : O(n²)
// Space Complexity : O(n²)
// ---------------------------------------------------------------

vector<vector<int>> rotateBruteForce(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n - i - 1] = matrix[i][j];
        }
    }

    return ans;
}

// ---------------------------------------------------------------
// 2. Better
// ---------------------------------------------------------------
//
// Rotate the matrix layer by layer using four-way swapping.
//
// We avoid creating another matrix, but the implementation is
// more involved.
//
// Time Complexity : O(n²)
// Space Complexity : O(1)
// ---------------------------------------------------------------

void rotateBetter(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int layer = 0; layer < n / 2; layer++)
    {
        int first = layer;
        int last = n - 1 - layer;

        for (int i = first; i < last; i++)
        {
            int offset = i - first;

            int top = matrix[first][i];

            matrix[first][i] =
                matrix[last - offset][first];

            matrix[last - offset][first] =
                matrix[last][last - offset];

            matrix[last][last - offset] =
                matrix[i][last];

            matrix[i][last] = top;
        }
    }
}

// ---------------------------------------------------------------
// 3. Optimal
// ---------------------------------------------------------------
//
// A 90° clockwise rotation can be achieved by:
//
// 1. Transpose the matrix.
// 2. Reverse every row.
//
// Example:
//
// Before transpose:
//
// 1 2 3
// 4 5 6
// 7 8 9
//
// After transpose:
//
// 1 4 7
// 2 5 8
// 3 6 9
//
// Reverse every row:
//
// 7 4 1
// 8 5 2
// 9 6 3
//
// Time Complexity : O(n²)
// Space Complexity : O(1)
// ---------------------------------------------------------------

void rotateOptimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);

    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
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
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

    vector<vector<int>> matrix1 = matrix;

    vector<vector<int>> ans =
        rotateBruteForce(matrix1);

    cout << "Brute Force :" << endl;
    printMatrix(ans);

    vector<vector<int>> matrix2 = matrix;

    rotateBetter(matrix2);

    cout << "\nBetter :" << endl;
    printMatrix(matrix2);

    vector<vector<int>> matrix3 = matrix;

    rotateOptimal(matrix3);

    cout << "\nOptimal :" << endl;
    printMatrix(matrix3);

    return 0;
}