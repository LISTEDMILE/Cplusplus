#include <iostream>
#include <vector>

using namespace std;

// ===============================================================
// Number of Provinces
// (DSU using Edge List)
// ===============================================================
//
// Instead of performing Union while
// traversing the matrix, we:
//
// 1. Create an edge list.
//
// 2. Traverse the edge list.
//
// 3. Perform Union on every edge.
//
// This makes the implementation
// similar to Kruskal's Algorithm.
//
// Time Complexity : O(N² × α(N))
//
// Space Complexity : O(N²)
// ===============================================================

// ---------------------------------------------------------------
// Find Ultimate Parent
// ---------------------------------------------------------------

int find(int Node,
         vector<int> &par)
{
    if (par[Node] == Node)

        return Node;

    return par[Node] =
               find(par[Node], par);
}

// ---------------------------------------------------------------
// Union by Size
// ---------------------------------------------------------------

void Union(int u,
           int v,
           vector<int> &par,
           vector<int> &Size)
{
    int parU = find(u, par);

    int parV = find(v, par);

    if (parU == parV)

        return;

    if (Size[parU] > Size[parV])
    {
        par[parV] = parU;

        Size[parU] += Size[parV];
    }
    else
    {
        par[parU] = parV;

        Size[parV] += Size[parU];
    }
}

// ---------------------------------------------------------------
// Number of Provinces
// ---------------------------------------------------------------

int findNumOfProvinces(vector<vector<int>> &roads,
                       int n)
{
    vector<int> par(n + 1);

    vector<int> Size(n + 1, 1);

    for (int i = 1; i <= n; i++)

        par[i] = i;

    // -----------------------------------------------------------
    // Create Edge List
    // -----------------------------------------------------------

    vector<pair<int, int>> edges;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (roads[i][j] == 1)

                edges.push_back({i + 1, j + 1});
        }
    }

    // -----------------------------------------------------------
    // Perform Union
    // -----------------------------------------------------------

    for (auto &it : edges)
    {
        Union(it.first,
              it.second,
              par,
              Size);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (par[i] == i)

            ans++;
    }

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<vector<int>> roads =
        {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}};

    cout << "Number of Provinces : "
         << findNumOfProvinces(roads, 3);

    return 0;
}