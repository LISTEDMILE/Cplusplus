#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// ===============================================================
// Shortest Path in Directed Acyclic Graph (DAG)
// ===============================================================
//
// We are given a weighted Directed
// Acyclic Graph (DAG).
//
// We have to find the shortest
// distance from source node 0
// to every other node.
//
// Idea:
//
// Step 1
// Perform Topological Sort using DFS.
//
// Step 2
// Store the nodes in a stack.
//
// Step 3
// Initialize
//
// dist[source] = 0
//
// Step 4
// Process nodes in Topological Order.
//
// Relax every outgoing edge.
//
// Since the graph is a DAG,
// every edge is processed only once.
//
// Time Complexity : O(V + E)
//
// Space Complexity : O(V + E)
// ===============================================================

// ===============================================================
// DFS for Topological Sort
// ===============================================================

void helper(vector<vector<pair<int, int>>> &adj,
            vector<int> &visited,
            stack<int> &s,
            int idx)
{

    visited[idx] = 1;

    for (auto it : adj[idx])
    {

        if (!visited[it.first])

            helper(adj,
                   visited,
                   s,
                   it.first);
    }

    s.push(idx);
}

// ===============================================================
// Shortest Path
// ===============================================================

vector<int> shortestPathInDAG(int n,
                              int m,
                              vector<vector<int>> &edges)
{

    stack<int> s;

    vector<vector<pair<int, int>>> adj(n);

    vector<int> visited(n);

    vector<int> dist(n, INT_MAX);

    // -----------------------------------------------------------
    // Create Adjacency List
    // -----------------------------------------------------------

    for (int i = 0; i < m; i++)
    {

        adj[edges[i][0]].push_back(
            {edges[i][1], edges[i][2]});
    }

    // -----------------------------------------------------------
    // Topological Sort
    // -----------------------------------------------------------

    for (int i = 0; i < n; i++)
    {

        if (!visited[i])

            helper(adj,
                   visited,
                   s,
                   i);
    }

    int src = 0;

    dist[src] = 0;

    // -----------------------------------------------------------
    // Relax Edges
    // -----------------------------------------------------------

    while (!s.empty())
    {

        int top = s.top();

        s.pop();

        for (auto it : adj[top])
        {

            if (dist[top] != INT_MAX)

                dist[it.first] =
                    min(dist[it.first],
                        dist[top] + it.second);
        }
    }

    // -----------------------------------------------------------
    // Replace Unreachable Nodes
    // -----------------------------------------------------------

    for (int i = 0; i < n; i++)
    {

        if (dist[i] == INT_MAX)

            dist[i] = -1;
    }

    return dist;
}

// ===============================================================
// Print Vector
// ===============================================================

void printVector(vector<int> &dist)
{

    for (int it : dist)

        cout << it << " ";

    cout << endl;
}

// ===============================================================
// Main
// ===============================================================

int main()
{

    int n = 6;

    vector<vector<int>> edges =
        {
            {0, 1, 2},
            {0, 4, 1},
            {1, 2, 3},
            {4, 2, 2},
            {4, 5, 4},
            {2, 3, 6},
            {5, 3, 1}};

    int m = edges.size();

    vector<int> dist =
        shortestPathInDAG(n, m, edges);

    cout << "Shortest Distance from Source 0\n";

    printVector(dist);

    return 0;
}