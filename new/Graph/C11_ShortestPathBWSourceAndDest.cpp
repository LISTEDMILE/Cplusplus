#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// ===============================================================
// Shortest Path Between Source and Destination
// (Dijkstra's Algorithm)
// ===============================================================
//
// We are given a weighted graph.
//
// Find the shortest path from
// source node s
// to
// destination node t.
//
// Idea:
//
// 1. Build the adjacency list.
//
// 2. Use Dijkstra's Algorithm
//    to compute the shortest distance.
//
// 3. Maintain a parent array.
//
// Whenever a shorter path is found,
// update the parent.
//
// 4. Start from destination and
// follow the parent array until
// reaching the source.
//
// Reverse the obtained path.
//
// Time Complexity : O((V + E) log V)
//
// Space Complexity : O(V + E)
// ===============================================================

vector<int> shortestPath(vector<vector<int>> &edges,
                         int n,
                         int m,
                         int s,
                         int t)
{

    vector<vector<pair<int, int>>> adj(n + 1);

    vector<int> dist(n + 1, INT_MAX);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        q;

    // -----------------------------------------------------------
    // Create Adjacency List
    // -----------------------------------------------------------

    for (int i = 0; i < m; i++)
    {

        adj[edges[i][0]].push_back(
            {edges[i][1], edges[i][2]});

        // Remove this line if graph is directed

        adj[edges[i][1]].push_back(
            {edges[i][0], edges[i][2]});
    }

    // -----------------------------------------------------------
    // Parent Array
    // -----------------------------------------------------------

    vector<int> par(n + 1);

    for (int i = 1; i <= n; i++)

        par[i] = i;

    dist[s] = 0;

    q.push({0, s});

    // -----------------------------------------------------------
    // Dijkstra's Algorithm
    // -----------------------------------------------------------

    while (!q.empty())
    {

        int node = q.top().second;

        int distance = q.top().first;

        q.pop();

        if (distance > dist[node])

            continue;

        for (auto &it : adj[node])
        {

            if (distance + it.second < dist[it.first])
            {

                dist[it.first] =
                    distance + it.second;

                par[it.first] = node;

                q.push(
                    {dist[it.first],
                     it.first});
            }
        }
    }

    // -----------------------------------------------------------
    // No Path Exists
    // -----------------------------------------------------------

    if (dist[t] == INT_MAX)

        return {-1};

    // -----------------------------------------------------------
    // Reconstruct Path
    // -----------------------------------------------------------

    vector<int> ans;

    int i = t;

    while (i != par[i])
    {

        ans.push_back(i);

        i = par[i];
    }

    ans.push_back(i);

    reverse(ans.begin(), ans.end());

    return ans;
}

// ===============================================================
// Print Path
// ===============================================================

void printPath(vector<int> &ans)
{

    for (int it : ans)

        cout << it << " ";

    cout << endl;
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
            {1, 4, 1},
            {2, 3, 4},
            {4, 3, 3},
            {4, 5, 5},
            {3, 5, 1}};

    int m = edges.size();

    int s = 1;

    int t = 5;

    vector<int> ans =
        shortestPath(edges,
                     n,
                     m,
                     s,
                     t);

    cout << "Shortest Path : ";

    printPath(ans);

    return 0;
}