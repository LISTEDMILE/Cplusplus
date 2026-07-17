#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// We have to find the minimum falling path sum.
//
// We can start from ANY element of the first row.
// We have to reach ANY element of the last row.
//
// Allowed moves:
//      Down        -> (i+1, j)
//      Left Down   -> (i+1, j-1)
//      Right Down  -> (i+1, j+1)
//
// We'll think in reverse.
// Instead of starting from the first row,
// we'll find the minimum path from (i,j) to the last row.

// ------------------------------------------------------------------
// Recursion
// ------------------------------------------------------------------

int minimumFallingPath(int r, int c, vector<vector<int>> &matrix)
{
    int n = matrix.size();

    if (c < 0 || c >= n)
        return INT_MAX;

    if (r == n - 1)
        return matrix[r][c];

    int leftBottom = minimumFallingPath(r + 1, c - 1, matrix);
    int bottom = minimumFallingPath(r + 1, c, matrix);
    int rightBottom = minimumFallingPath(r + 1, c + 1, matrix);

    return matrix[r][c] + min(min(leftBottom, bottom), rightBottom);
}

// ------------------------------------------------------------------
// Memoization
// ------------------------------------------------------------------

int minimumFallingPathOptimalMemoization(int r, int c,
                                         vector<vector<int>> &matrix,
                                         vector<vector<int>> &dp)
{
    int n = matrix.size();

    if (c < 0 || c >= n)
        return INT_MAX;

    if (r == n - 1)
        return matrix[r][c];

    if (dp[r][c] != -1)
        return dp[r][c];

    int leftBottom = minimumFallingPathOptimalMemoization(r + 1, c - 1, matrix, dp);
    int bottom = minimumFallingPathOptimalMemoization(r + 1, c, matrix, dp);
    int rightBottom = minimumFallingPathOptimalMemoization(r + 1, c + 1, matrix, dp);

    return dp[r][c] = matrix[r][c] +
                      min(min(leftBottom, bottom), rightBottom);
}

// ------------------------------------------------------------------
// Tabulation
//
// This time we'll start from the last row.
// Last row itself becomes the base case.
// Then we'll move upwards.
// ------------------------------------------------------------------

int minimumFallingPathOptimalTabulation(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base Case

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = matrix[n - 1][j];
    }

    // Build Answer

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            int leftBottom = INT_MAX;
            int rightBottom = INT_MAX;

            if (j > 0)
                leftBottom = matrix[i][j] + dp[i + 1][j - 1];

            int bottom = matrix[i][j] + dp[i + 1][j];

            if (j < n - 1)
                rightBottom = matrix[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(min(leftBottom, bottom), rightBottom);
        }
    }

    int ans = INT_MAX;

    for (int j = 0; j < n; j++)
        ans = min(ans, dp[0][j]);

    return ans;
}

// ------------------------------------------------------------------
// Space Optimization
//
// Every row depends only on the row below.
// So we'll keep only one previous row.
// ------------------------------------------------------------------

int minimumFallingPathMostOptimized(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    vector<int> prev(n);

    // Base Case

    for (int j = 0; j < n; j++)
        prev[j] = matrix[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp(n);

        for (int j = 0; j < n; j++)
        {
            int leftBottom = INT_MAX;
            int rightBottom = INT_MAX;

            if (j > 0)
                leftBottom = matrix[i][j] + prev[j - 1];

            int bottom = matrix[i][j] + prev[j];

            if (j < n - 1)
                rightBottom = matrix[i][j] + prev[j + 1];

            temp[j] = min(min(leftBottom, bottom), rightBottom);
        }

        prev = temp;
    }

    int ans = INT_MAX;

    for (int j = 0; j < n; j++)
        ans = min(ans, prev[j]);

    return ans;
}

int main()
{
    vector<vector<int>> matrix =
        {
            {2, 1, 3},
            {6, 5, 4},
            {7, 8, 9}};

    int n = matrix.size();

    cout << "Minimum Falling Path Sum (Recursion) : ";

    int ans = INT_MAX;

    for (int j = 0; j < n; j++)
        ans = min(ans, minimumFallingPath(0, j, matrix));

    cout << ans;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    ans = INT_MAX;

    for (int j = 0; j < n; j++)
        ans = min(ans,
                  minimumFallingPathOptimalMemoization(0, j, matrix, dp));

    cout << "\nMinimum Falling Path Sum (Memoization) : "
         << ans;

    cout << "\nMinimum Falling Path Sum (Tabulation) : "
         << minimumFallingPathOptimalTabulation(matrix);

    cout << "\nMinimum Falling Path Sum (Most Optimized) : "
         << minimumFallingPathMostOptimized(matrix);

    return 0;
}