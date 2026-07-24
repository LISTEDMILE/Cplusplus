#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// ===============================================================
// Number of Ways to Arrive at Destination
// ===============================================================
//
// We are given an undirected weighted graph.
//
// We have to find:
//
// 1. The shortest time required to
//    reach node (n-1).
//
// 2. The number of different shortest
//    paths.
//
// Idea:
//
// This is a modified version of
// Dijkstra's Algorithm.
//
// dist[i]
// -> Shortest time to reach node i.
//
// ways[i]
// -> Number of shortest paths to
//    reach node i.
//
// Cases:
//
// 1. Smaller Distance Found
//
//    Update distance.
//
//    Copy the number of ways from
//    the parent node.
//
// 2. Same Distance Found
//
//    Add the number of ways.
//
// Time Complexity : O((V + E) log V)
//
// Space Complexity : O(V + E)
// ===============================================================

int countPaths(int n,
               vector<vector<int>> &roads)
{

    vector<vector<pair<int, int>>> adj(n);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>>
        q;

    vector<long long> dist(
        n,
        LLONG_MAX);

    vector<int> ways(n, 0);

    // -----------------------------------------------------------
    // Create Adjacency List
    // -----------------------------------------------------------

    for (int i = 0; i < roads.size(); i++)
    {

        adj[roads[i][0]].push_back(
            {roads[i][1], roads[i][2]});

        adj[roads[i][1]].push_back(
            {roads[i][0], roads[i][2]});
    }

    q.push({0, 0});

    dist[0] = 0;

    ways[0] = 1;

    const int MOD = 1e9 + 7;

    // -----------------------------------------------------------
    // Dijkstra's Algorithm
    // -----------------------------------------------------------

    while (!q.empty())
    {

        long long time = q.top().first;

        int node = q.top().second;

        q.pop();

        if (time > dist[node])

            continue;

        for (auto it : adj[node])
        {

            int bwTime = it.second;

            int currNode = it.first;

            // -----------------------------------------------
            // Better Shortest Path Found
            // -----------------------------------------------

            if (bwTime + time < dist[currNode])
            {

                ways[currNode] = ways[node];

                dist[currNode] = time + bwTime;

                q.push(
                    {time + bwTime,
                     currNode});
            }

            // -----------------------------------------------
            // Another Shortest Path Found
            // -----------------------------------------------

            else if (bwTime + time == dist[currNode])
            {

                ways[currNode] =
                    (ways[node] +
                     ways[currNode]) %
                    MOD;
            }
        }
    }

    return ways[n - 1];
}

// ===============================================================
// Main
// ===============================================================

int main()
{

    int n = 7;

    vector<vector<int>> roads =
        {
            {0, 6, 7},
            {0, 1, 2},
            {1, 2, 3},
            {1, 3, 3},
            {6, 3, 3},
            {3, 5, 1},
            {6, 5, 1},
            {2, 5, 1},
            {0, 4, 5},
            {4, 6, 2}};

    cout << "Number of Shortest Paths : "
         << countPaths(n, roads);

    return 0;
}