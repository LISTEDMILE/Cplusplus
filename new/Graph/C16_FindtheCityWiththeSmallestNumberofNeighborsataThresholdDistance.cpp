#include <iostream>
#include <vector>

using namespace std;

// ===============================================================
// Find the City With the Smallest Number of Neighbors
// at a Threshold Distance
// ===============================================================
//
// We are given:
//
// n      -> Number of cities
// edges  -> {u, v, weight}
// distanceThreshold
//
// We have to find the city that can
// reach the smallest number of cities
// whose shortest distance is less than
// or equal to distanceThreshold.
//
// If multiple cities have the same
// minimum count, return the city with
// the greatest index.
//
// Idea:
//
// 1. Build an adjacency matrix.
//
// 2. Apply Floyd-Warshall Algorithm
//    to compute the shortest distance
//    between every pair of cities.
//
// 3. Count how many cities are
//    reachable within the threshold.
//
// 4. If two cities have the same count,
//    choose the larger index.
//
// Time Complexity : O(N³)
//
// Space Complexity : O(N²)
// ===============================================================

int findTheCity(int n,
                vector<vector<int>> &edges,
                int distanceThreshold)
{

    const int M = 1e9;

    vector<vector<int>> adj(
        n,
        vector<int>(n, M));

    // -----------------------------------------------------------
    // Create Adjacency Matrix
    // -----------------------------------------------------------

    for (auto &it : edges)
    {

        adj[it[0]][it[1]] = it[2];

        adj[it[1]][it[0]] = it[2];
    }

    for (int i = 0; i < n; i++)

        adj[i][i] = 0;

    // -----------------------------------------------------------
    // Floyd-Warshall Algorithm
    // -----------------------------------------------------------

    for (int k = 0; k < n; k++)
    {

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                if (adj[i][k] == 1e9 &&
                    adj[k][j] == 1e9)

                    continue;

                if (adj[i][j] >
                    adj[i][k] + adj[k][j])

                    adj[i][j] =
                        adj[i][k] +
                        adj[k][j];
            }
        }
    }

    // -----------------------------------------------------------
    // Find City With Minimum Reachable Cities
    // -----------------------------------------------------------

    int cityWithLeastCities = -1;

    int leastCities = n + 1;

    for (int i = 0; i < n; i++)
    {

        int count = 0;

        for (int j = 0; j < n; j++)

            if (adj[i][j] <= distanceThreshold)

                count++;

        if (count <= leastCities)
        {

            cityWithLeastCities = i;

            leastCities = count;
        }
    }

    return cityWithLeastCities;
}

// ===============================================================
// Main
// ===============================================================

int main()
{

    int n = 4;

    vector<vector<int>> edges =
        {
            {0, 1, 3},
            {1, 2, 1},
            {1, 3, 4},
            {2, 3, 1}};

    int distanceThreshold = 4;

    cout << "City : "
         << findTheCity(
                n,
                edges,
                distanceThreshold);

    return 0;
}