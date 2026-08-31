#include <bits/stdc++.h>
using namespace std;

// First DFS:
// Find finishing order of all nodes.
void dfs(int node,
         vector<vector<int>> &adj,
         vector<int> &visited,
         stack<int> &s)
{
    visited[node] = 1;

    for (int it : adj[node])
    {
        if (!visited[it])
            dfs(it, adj, visited, s);
    }

    s.push(node);
}

// Second DFS:
// Traverse the reversed graph.
// Every DFS here gives one Strongly Connected Component.
void dfs2(int node,
          vector<vector<int>> &adj,
          vector<int> &visited)
{
    visited[node] = 1;

    for (int it : adj[node])
    {
        if (!visited[it])
            dfs2(it, adj, visited);
    }
}

int stronglyConnectedComponents(int v,
                                vector<vector<int>> &edges)
{
    vector<int> visited(v, 0);
    stack<int> s;

    vector<vector<int>> adj(v);
    vector<vector<int>> rev(v);

    // Create original graph and reversed graph
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        rev[it[1]].push_back(it[0]);
    }

    // -------------------------------------------------------
    // Step 1:
    // DFS on original graph and store nodes according
    // to their finishing time.
    // -------------------------------------------------------

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, s);
        }
    }

    int ans = 0;

    // Reset visited array
    fill(visited.begin(), visited.end(), 0);

    // -------------------------------------------------------
    // Step 2:
    // Process nodes in decreasing finishing order
    // on the reversed graph.
    //
    // Every DFS gives exactly one SCC.
    // -------------------------------------------------------

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (!visited[node])
        {
            ans++;
            dfs2(node, rev, visited);
        }
    }

    return ans;
}

int main()
{
    int v = 5;

    vector<vector<int>> edges = {
        {0, 2},
        {2, 1},
        {1, 0},
        {0, 3},
        {3, 4}};

    cout << "Number of Strongly Connected Components: "
         << stronglyConnectedComponents(v, edges)
         << endl;

    return 0;
}