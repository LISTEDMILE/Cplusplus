#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPar(vector<int> &par, int node)
    {
        if (node == par[node])
            return node;

        return par[node] = findPar(par, par[node]);
    }

    void joinBySize(vector<int> &par,
                    vector<int> &size,
                    int u,
                    int v)
    {
        int parU = findPar(par, u);
        int parV = findPar(par, v);

        if (parU == parV)
            return;

        if (size[parV] > size[parU])
        {
            par[parU] = parV;
            size[parV] += size[parU];
        }
        else
        {
            par[parV] = parU;
            size[parU] += size[parV];
        }
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<int> par(n * n);
        vector<int> size(n * n, 1);

        int itX[] = {0, 0, -1, 1};
        int itY[] = {-1, 1, 0, 0};

        for (int i = 0; i < n * n; i++)
            par[i] = i;

        int ans = 0;

        // -------------------------------------------------------
        // Step 1: Connect all existing 1s using DSU
        // -------------------------------------------------------

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int c = 0; c < 4; c++)
                    {
                        int row = i + itX[c];
                        int col = j + itY[c];

                        if (row < n &&
                            col < n &&
                            row >= 0 &&
                            col >= 0 &&
                            grid[row][col])
                        {
                            int u = i * n + j;
                            int v = row * n + col;

                            if (findPar(par, u) != findPar(par, v))
                            {
                                joinBySize(par, size, u, v);
                            }

                            ans = max(ans, size[findPar(par, u)]);
                        }
                    }
                }
            }
        }

        // -------------------------------------------------------
        // Step 2: Try converting every 0 into 1
        //
        // Use a set so that the same island is not counted twice.
        // -------------------------------------------------------

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                unordered_set<int> s;

                if (grid[i][j] == 0)
                {
                    for (int c = 0; c < 4; c++)
                    {
                        int row = i + itX[c];
                        int col = j + itY[c];

                        if (row < n &&
                            col < n &&
                            row >= 0 &&
                            col >= 0 &&
                            grid[row][col])
                        {
                            int v = row * n + col;

                            s.insert(findPar(par, v));
                        }
                    }
                }

                // Current 0 becomes 1
                int count = 1;

                // Add all unique neighbouring components
                for (int a : s)
                    count += size[a];

                ans = max(ans, count);
            }
        }

        return ans;
    }
};