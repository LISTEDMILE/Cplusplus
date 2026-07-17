#include <iostream>
#include <vector>

using namespace std;

// ===============================================================
// Number of Islands
// ===============================================================
//
// We are given a grid consisting of
// '1' -> Land
// '0' -> Water
//
// An island is formed by connecting
// adjacent lands horizontally or vertically.
//
// We have to count the total number
// of islands.
//
// We solve it using DFS.
//
// ---------------------------------------------------------------
// Approach 1
// Using a Visited Array
// ---------------------------------------------------------------
//
// We keep the original grid unchanged.
//
// Whenever we find an unvisited land,
// we start a DFS and mark all connected
// land cells as visited.
//
// Time Complexity : O(N × M)
// Space Complexity : O(N × M)
// ===============================================================

void helperUsingVisited(vector<vector<char>> &grid,
                        vector<vector<bool>> &visited,
                        int i,
                        int j,
                        int n,
                        int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;

    if (grid[i][j] == '0' || visited[i][j])
        return;

    visited[i][j] = true;

    helperUsingVisited(grid, visited, i, j - 1, n, m);
    helperUsingVisited(grid, visited, i, j + 1, n, m);
    helperUsingVisited(grid, visited, i + 1, j, n, m);
    helperUsingVisited(grid, visited, i - 1, j, n, m);
}

int numIslandsUsingVisited(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int ans = 0;

    vector<vector<bool>> visited(
        n,
        vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' &&
                !visited[i][j])
            {
                ans++;

                helperUsingVisited(
                    grid,
                    visited,
                    i,
                    j,
                    n,
                    m);
            }
        }
    }

    return ans;
}

// ===============================================================
// Approach 2
// Without Using a Visited Array
// ===============================================================
//
// Instead of maintaining a separate
// visited array, we directly convert
// every visited land into water.
//
// This saves extra memory.
//
// Time Complexity : O(N × M)
// Space Complexity : O(1)
// (excluding recursion stack)
// ===============================================================

void helperWithoutVisited(vector<vector<char>> &grid,
                          int i,
                          int j,
                          int n,
                          int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    helperWithoutVisited(grid, i, j - 1, n, m);
    helperWithoutVisited(grid, i, j + 1, n, m);
    helperWithoutVisited(grid, i + 1, j, n, m);
    helperWithoutVisited(grid, i - 1, j, n, m);
}

int numIslandsWithoutVisited(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                ans++;

                helperWithoutVisited(
                    grid,
                    i,
                    j,
                    n,
                    m);
            }
        }
    }

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<vector<char>> grid =
        {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}};

    vector<vector<char>> gridCopy = grid;

    cout << "Using Visited Array : "
         << numIslandsUsingVisited(grid)
         << endl;

    cout << "Without Visited Array : "
         << numIslandsWithoutVisited(gridCopy)
         << endl;

    return 0;
}