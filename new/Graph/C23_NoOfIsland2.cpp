#include <bits/stdc++.h>
using namespace std;

// Find parent with Path Compression
int findPar(vector<int> &par, int node)
{
    if (par[node] == node)
        return node;

    return par[node] = findPar(par, par[node]);
}

// Union by Size
void unionBySize(vector<int> &par,
                 vector<int> &size,
                 int u,
                 int v)
{
    int parU = findPar(par, u);
    int parV = findPar(par, v);

    if (parU == parV)
        return;

    if (size[parU] > size[parV])
    {
        size[parU] += size[parV];
        par[parV] = parU;
    }
    else
    {
        size[parV] += size[parU];
        par[parU] = parV;
    }
}

// Number of Islands II
//
// Initially, every cell is water.
//
// For every query:
// 1. Convert the cell into land.
// 2. Increase island count.
// 3. Check its 4 neighbours.
// 4. If a neighbouring cell is already land
//    and belongs to a different component,
//    merge them and decrease island count.
//
// DSU is used to efficiently merge islands.

vector<int> numOfIslandsII(int n,
                           int m,
                           vector<vector<int>> &q)
{
    vector<int> par(n * m);
    vector<int> size(n * m, 1);
    vector<vector<int>> visited(n, vector<int>(m, 0));

    vector<int> ans;
    int count = 0;

    int itX[] = {-1, 1, 0, 0};
    int itY[] = {0, 0, -1, 1};

    for (int i = 0; i < n * m; i++)
        par[i] = i;

    for (auto it : q)
    {
        int i = it[0];
        int j = it[1];

        // Duplicate query
        if (visited[i][j])
        {
            ans.push_back(count);
            continue;
        }

        // New land creates a new island
        count++;
        visited[i][j] = 1;

        for (int c = 0; c < 4; c++)
        {
            int x = i + itX[c];
            int y = j + itY[c];

            if (x < n && x >= 0 &&
                y >= 0 && y < m &&
                visited[x][y])
            {
                int u = i * m + j;
                int v = x * m + y;

                // Different islands -> merge them
                if (findPar(par, u) != findPar(par, v))
                {
                    count--;
                    unionBySize(par, size, u, v);
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}

// ---------------------------------------------------------------
// Test
// ---------------------------------------------------------------

int main()
{
    int n = 4;
    int m = 5;

    vector<vector<int>> q = {
        {1, 1},
        {0, 1},
        {3, 3},
        {3, 4},
        {1, 2},
        {1, 1},
        {0, 0},
        {0, 3},
        {1, 4},
        {2, 4},
        {3, 2}};

    vector<int> ans = numOfIslandsII(n, m, q);

    cout << "Number of Islands after each query:\n";

    for (int it : ans)
        cout << it << " ";

    cout << endl;

    return 0;
}