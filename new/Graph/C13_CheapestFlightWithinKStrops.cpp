#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// ===============================================================
// Cheapest Flights Within K Stops
// ===============================================================
//
// We are given:
//
// n         -> Number of cities
// flights   -> {source, destination, price}
// src       -> Starting city
// dst       -> Destination city
// k         -> Maximum allowed stops
//
// We have to find the minimum cost
// to travel from src to dst using
// at most k stops.
//
// Idea:
//
// Create an adjacency list.
//
// Perform a BFS where every queue
// element stores:
//
// 1. Number of stops used
// 2. Current node
// 3. Cost to reach that node
//
// If we find a cheaper cost for a
// neighbouring city, update it and
// push it into the queue.
//
// Time Complexity : O(E)
//
// Space Complexity : O(V + E)
// ===============================================================

int findCheapestPrice(int n,
                      vector<vector<int>> &flights,
                      int src,
                      int dst,
                      int k)
{

    vector<vector<pair<int, int>>> adj(n);

    // -----------------------------------------------------------
    // Create Adjacency List
    // -----------------------------------------------------------

    for (int i = 0; i < flights.size(); i++)
    {

        adj[flights[i][0]].push_back(
            {flights[i][1],
             flights[i][2]});
    }

    queue<pair<int, pair<int, int>>> q;

    q.push({0, {src, 0}});

    vector<int> dist(n, INT_MAX);

    dist[src] = 0;

    // -----------------------------------------------------------
    // BFS
    // -----------------------------------------------------------

    while (!q.empty())
    {

        int stops = q.front().first;

        int node = q.front().second.first;

        int distToNode = q.front().second.second;

        q.pop();

        if (stops > k)

            break;

        for (auto it : adj[node])
        {

            int weight = it.second;

            int destNode = it.first;

            if (dist[destNode] > weight + distToNode)
            {

                q.push(
                    {stops + 1,
                     {destNode,
                      weight + distToNode}});

                dist[destNode] =
                    weight + distToNode;
            }
        }
    }

    if (dist[dst] == INT_MAX)

        return -1;

    return dist[dst];
}

// ===============================================================
// Main
// ===============================================================

int main()
{

    int n = 4;

    vector<vector<int>> flights =
        {
            {0, 1, 100},
            {1, 2, 100},
            {2, 3, 100},
            {0, 2, 500}};

    int src = 0;

    int dst = 3;

    int k = 1;

    cout << "Minimum Cost : "
         << findCheapestPrice(
                n,
                flights,
                src,
                dst,
                k);

    return 0;
}