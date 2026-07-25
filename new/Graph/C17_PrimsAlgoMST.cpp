#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ===============================================================
// Prim's Minimum Spanning Tree (MST)
// ===============================================================
//
// Given an undirected weighted graph,
// find the Minimum Spanning Tree.
//
// A Minimum Spanning Tree is a subset
// of edges that:
//
// 1. Connects all vertices.
// 2. Contains exactly (V-1) edges.
// 3. Has the minimum possible total weight.
//
// Idea:
//
// We use a Min Heap (Priority Queue).
//
// Each element stores:
//
// {weight, {node, parent}}
//
// Initially,
// start from node 1.
//
// Always pick the edge with the
// minimum weight that connects a
// visited node to an unvisited node.
//
// Time Complexity : O(E log E)
//
// Space Complexity : O(V + E)
// ===============================================================

vector<pair<pair<int, int>, int>> calculatePrimsMST(
    int n,
    int m,
    vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int, int>>> adj(n + 1);

    // -----------------------------------------------------------
    // Create Adjacency List
    // -----------------------------------------------------------

    for (auto &it : g)
    {

        int u = it.first.first;

        int v = it.first.second;

        int w = it.second;

        adj[u].push_back({v, w});

        adj[v].push_back({u, w});
    }

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        q;

    vector<int> visited(n + 1, 0);

    vector<pair<pair<int, int>, int>> ans;

    q.push({0, {1, -1}});

    // -----------------------------------------------------------
    // Prim's Algorithm
    // -----------------------------------------------------------

    while (!q.empty())
    {

        int wt = q.top().first;

        int node = q.top().second.first;

        int par = q.top().second.second;

        q.pop();

        if (visited[node])

            continue;

        visited[node] = 1;

        // Ignore starting node
        if (par != -1)
        {

            ans.push_back({{par, node}, wt});
        }

        for (auto it : adj[node])
        {

            int v = it.first;

            int w = it.second;

            if (!visited[v])

                q.push({w, {v, node}});
        }
    }

    return ans;
}

// ===============================================================
// Print MST
// ===============================================================

void printMST(vector<pair<pair<int, int>, int>> &ans)
{

    int totalWeight = 0;

    cout << "Edges in MST:\n";

    for (auto &it : ans)
    {

        cout << it.first.first
             << " - "
             << it.first.second
             << " (Weight = "
             << it.second
             << ")\n";

        totalWeight += it.second;
    }

    cout << "\nTotal Weight = "
         << totalWeight << endl;
}

// ===============================================================
// Main
// ===============================================================

int main()
{

    int n = 5;

    vector<pair<pair<int, int>, int>> g =
        {
            {{1, 2}, 2},
            {{1, 4}, 6},
            {{2, 3}, 3},
            {{2, 4}, 8},
            {{2, 5}, 5},
            {{3, 5}, 7},
            {{4, 5}, 9}};

    int m = g.size();

    vector<pair<pair<int, int>, int>> ans =
        calculatePrimsMST(n, m, g);

    printMST(ans);

    return 0;
}