#include <iostream>
#include <vector>

using namespace std;

// We have to find the minimum path sum from the top of the triangle
// We can move only to:
//      Down      -> (i+1, j)
//      RightDown -> (i+1, j+1)
//
// Starting point is fixed (0,0)
// Ending point is variable (any element of the last row)
//
// We'll think from (i,j) to the last row.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int minimumPath(int r, int c, vector<vector<int>> &triangle)
{
    int n = triangle.size();

    if (r == n - 1)
        return triangle[r][c];

    int down = minimumPath(r + 1, c, triangle);
    int rightDown = minimumPath(r + 1, c + 1, triangle);

    return triangle[r][c] + min(down, rightDown);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int minimumPathOptimalMemoization(int r, int c,
                                  vector<vector<int>> &triangle,
                                  vector<vector<int>> &dp)
{
    int n = triangle.size();

    if (r == n - 1)
        return triangle[r][c];

    if (dp[r][c] != -1)
        return dp[r][c];

    int down = minimumPathOptimalMemoization(r + 1, c, triangle, dp);
    int rightDown = minimumPathOptimalMemoization(r + 1, c + 1, triangle, dp);

    return dp[r][c] = triangle[r][c] + min(down, rightDown);
}

// ---------------------------------------------------------------
// Tabulation
// This time we'll start from the last row.
// Last row itself is the base case.
// Then move upwards.
// ---------------------------------------------------------------

int minimumPathOptimalTabulation(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base Case

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Build Answer

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int rightDown = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, rightDown);
        }
    }

    return dp[0][0];
}

// ---------------------------------------------------------------
// Space Optimization
// Since every row only depends on the row below,
// we only keep one previous row.
// ---------------------------------------------------------------

int minimumPathMostOptimized(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    vector<int> prev(n);

    // Base Case

    for (int j = 0; j < n; j++)
    {
        prev[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp(n);

        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + prev[j];
            int rightDown = triangle[i][j] + prev[j + 1];

            temp[j] = min(down, rightDown);
        }

        prev = temp;
    }

    return prev[0];
}

int main()
{
    vector<vector<int>> triangle =
        {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}};

    cout << "Minimum Path Sum (Recursion) : "
         << minimumPath(0, 0, triangle);

    vector<vector<int>> dp(triangle.size(),
                           vector<int>(triangle.size(), -1));

    cout << "\nMinimum Path Sum (Memoization) : "
         << minimumPathOptimalMemoization(0, 0, triangle, dp);

    cout << "\nMinimum Path Sum (Tabulation) : "
         << minimumPathOptimalTabulation(triangle);

    cout << "\nMinimum Path Sum (Most Optimized) : "
         << minimumPathMostOptimized(triangle);

    return 0;
}