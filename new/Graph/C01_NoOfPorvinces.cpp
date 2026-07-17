#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------
// Number of Provinces
// ---------------------------------------------------------------
//
// We are given an adjacency matrix.
//
// isConnected[i][j] = 1
// means city i and city j are directly connected.
//
// A Province is a group of cities
// that are directly or indirectly connected.
//
// Idea:
//
// Step 1:
// Convert the adjacency matrix
// into an adjacency list.
//
// Step 2:
// Traverse every node.
//
// Whenever we find an unvisited node,
// it means we have discovered a new province.
//
// Perform DFS to visit all cities
// belonging to that province.
//
// Increase the province count.
//
// Time Complexity : O(V²)
// Space Complexity : O(V + E)
// ---------------------------------------------------------------

void helper(vector<vector<int>> &adj,
            vector<bool> &visited,
            int idx)
{
    visited[idx] = true;

    for (int it : adj[idx])
    {
        if (!visited[it])
        {
            helper(adj,
                   visited,
                   it);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();

    int ans = 0;

    vector<bool> visited(n, false);

    vector<vector<int>> adj(n);

    // -----------------------------------------------------------
    // Convert Adjacency Matrix
    // into Adjacency List
    // -----------------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] && i != j)
            {
                adj[i].push_back(j);
            }
        }
    }

    // -----------------------------------------------------------
    // Count Connected Components
    // -----------------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans++;

            helper(adj,
                   visited,
                   i);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> isConnected =
        {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}};

    cout << "Number of Provinces : "
         << findCircleNum(isConnected);

    return 0;
}