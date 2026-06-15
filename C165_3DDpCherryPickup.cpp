#include <iostream>
#include <vector>

using namespace std;

// We have two robots.
//
// Robot 1 starts from (0,0)
// Robot 2 starts from (0,m-1)
//
// Both robots move simultaneously to the next row.
//
// Allowed Moves:
//      Left Diagonal
//      Down
//      Right Diagonal
//
// If both robots reach the same cell,
// we'll count that cell only once.
//
// State:
// dp[i][j1][j2]
// i  -> Current Row
// j1 -> Robot 1 Column
// j2 -> Robot 2 Column

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int cherryPickup(int i, int j1, int j2, vector<vector<int>> &g, int n, int m)
{
    if (j1 < 0 || j1 > m - 1 || j2 < 0 || j2 > m - 1)
    {
        return -1e8;
    }

    if (i == n - 1)
    {
        if (j1 == j2)
        {
            return g[i][j1];
        }
        else
            return g[i][j1] + g[i][j2];
    }

    int maxx = -1e8;

    for (int k = -1; k <= 1; k++)
    {
        for (int l = -1; l <= 1; l++)
        {
            if (j1 == j2)
                maxx = max(maxx, (g[i][j1] + cherryPickup(i + 1, j1 + k, j2 + l, g, n, m)));
            else
                maxx = max(maxx, g[i][j1] + g[i][j2] + cherryPickup(i + 1, j1 + k, j2 + l, g, n, m));
        }
    }

    return maxx;
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int cherryPickupOptimalMemoization(int i, int j1, int j2, vector<vector<int>> &g, int n, int m, vector<vector<vector<int>>> &p)
{
    if (j1 < 0 || j1 > m - 1 || j2 < 0 || j2 > m - 1)
    {
        return -1e8;
    }

    if (i == n - 1)
    {
        if (j1 == j2)
        {
            return g[i][j1];
        }
        else
            return g[i][j1] + g[i][j2];
    }

    if (p[i][j1][j2] != -1)
        return p[i][j1][j2];

    int maxx = -1e8;

    for (int k = -1; k <= 1; k++)
    {
        for (int l = -1; l <= 1; l++)
        {
            if (j1 == j2)
                maxx = max(maxx, (g[i][j1] + cherryPickupOptimalMemoization(i + 1, j1 + k, j2 + l, g, n, m, p)));
            else
                maxx = max(maxx, g[i][j1] + g[i][j2] + cherryPickupOptimalMemoization(i + 1, j1 + k, j2 + l, g, n, m, p));
        }
    }

    return p[i][j1][j2] = maxx;
}

// ---------------------------------------------------------------
// Tabulation
//
// Base Case = Last Row
// Then move upwards.
// ---------------------------------------------------------------

int cherryPickupOptimalTabulation(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> p(n, vector<vector<int>>(m, vector<int>(m, -1)));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                p[n - 1][j1][j2] = grid[n - 1][j1];
            else
                p[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxx = -1e8;

                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        if (j1 + k < m && j1 + k >= 0 && j2 + l >= 0 && j2 + l < m)
                        {
                            if (j1 == j2)
                                maxx = max(maxx, grid[i][j1] + p[i + 1][j1 + k][j2 + l]);
                            else
                                maxx = max(maxx, grid[i][j1] + grid[i][j2] + p[i + 1][j1 + k][j2 + l]);
                        }
                    }
                }

                p[i][j1][j2] = maxx;
            }
        }
    }

    return p[0][0][m - 1];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Every row depends only on the next row.
// ---------------------------------------------------------------

int cherryPickupMostOptimized(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> p(m, vector<int>(m));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                p[j1][j2] = grid[n - 1][j1];
            else
                p[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> temp(m, vector<int>(m));

        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxx = -1e8;

                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        if (j1 + k < m && j1 + k >= 0 && j2 + l >= 0 && j2 + l < m)
                        {
                            if (j1 == j2)
                                maxx = max(maxx, grid[i][j1] + p[j1 + k][j2 + l]);
                            else
                                maxx = max(maxx, grid[i][j1] + grid[i][j2] + p[j1 + k][j2 + l]);
                        }
                    }
                }

                temp[j1][j2] = maxx;
            }
        }

        p = temp;
    }

    return p[0][m - 1];
}

int main()
{
    vector<vector<int>> grid =
        {
            {3, 1, 1},
            {2, 5, 1},
            {1, 5, 5},
            {2, 1, 1}};

    int n = grid.size();
    int m = grid[0].size();

    cout << "Maximum Cherries (Recursion) : "
         << cherryPickup(0, 0, m - 1, grid, n, m);

    vector<vector<vector<int>>> p(n,
                                  vector<vector<int>>(m,
                                                      vector<int>(m, -1)));

    cout << "\nMaximum Cherries (Memoization) : "
         << cherryPickupOptimalMemoization(0, 0, m - 1, grid, n, m, p);

    cout << "\nMaximum Cherries (Tabulation) : "
         << cherryPickupOptimalTabulation(grid);

    cout << "\nMaximum Cherries (Most Optimized) : "
         << cherryPickupMostOptimized(grid);

    return 0;
}