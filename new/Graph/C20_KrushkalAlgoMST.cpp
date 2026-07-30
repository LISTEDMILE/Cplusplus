#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ===============================================================
// Kruskal's Minimum Spanning Tree (MST)
// ===============================================================
//
// Given an undirected weighted graph,
// find the Minimum Spanning Tree.
//
// Kruskal's Algorithm:
//
// 1. Sort all edges in increasing order
//    of weight.
//
// 2. Process edges one by one.
//
// 3. If the endpoints belong to
//    different components,
//    include the edge in the MST.
//
// 4. Merge both components using
//    Disjoint Set Union (DSU).
//
// Time Complexity:
//
// Sorting : O(E log E)
//
// DSU Operations : O(E × α(V))
//
// Overall : O(E log E)
//
// Space Complexity : O(V)
// ===============================================================

// ---------------------------------------------------------------
// Find Ultimate Parent
// (Path Compression)
// ---------------------------------------------------------------

int find(int node, vector<int> &par)
{
    if (par[node] == node)

        return node;

    return par[node] = find(par[node], par);
}

// ---------------------------------------------------------------
// Kruskal's Algorithm
// ---------------------------------------------------------------

int kruskalMST(int n,
               vector<vector<int>> &edges)
{
    sort(edges.begin(),
         edges.end(),
         [](const vector<int> &a,
            const vector<int> &b)
         {
             return a[2] < b[2];
         });

    vector<int> par(n + 1);

    vector<int> rank(n + 1, 0);

    int w = 0;

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    for (auto &ed : edges)
    {
        int parU = find(ed[0], par);

        int parV = find(ed[1], par);

        // Edge forms a cycle
        if (parU == parV)

            continue;

        w += ed[2];

        if (rank[parU] == rank[parV])
        {
            par[parV] = parU;

            rank[parU]++;
        }
        else if (rank[parU] > rank[parV])

            par[parV] = parU;

        else

            par[parU] = parV;
    }

    return w;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    int n = 5;

    vector<vector<int>> edges =
        {
            {1, 2, 2},
            {1, 4, 6},
            {2, 3, 3},
            {2, 4, 8},
            {2, 5, 5},
            {3, 5, 7},
            {4, 5, 9}};

    cout << "Weight of MST : "
         << kruskalMST(n, edges);

    return 0;
}