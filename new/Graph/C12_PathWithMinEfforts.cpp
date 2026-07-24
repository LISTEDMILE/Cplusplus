#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

// ===============================================================
// Path With Minimum Effort
// ===============================================================
//
// We are given a matrix of heights.
//
// We have to travel from
// (0,0)
// to
// (n-1,m-1).
//
// The effort of a path is defined as
// the maximum absolute difference
// between the heights of two
// consecutive cells in that path.
//
// We have to minimize this maximum effort.
//
// Idea:
//
// This is a modified version of
// Dijkstra's Algorithm.
//
// Instead of storing the minimum
// distance,
// we store the minimum effort required
// to reach every cell.
//
// While moving to a neighbouring cell:
//
// newEffort =
// max(currentEffort,
// abs(heightDifference))
//
// If this effort is smaller than the
// previously stored effort,
// update it.
//
// Time Complexity : O((N × M) log(N × M))
//
// Space Complexity : O(N × M)
// ===============================================================

int minimumEffortPath(vector<vector<int>> &heights)
{

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        q;

    int n = heights.size();

    int m = heights[0].size();

    vector<vector<int>> dist(
        n,
        vector<int>(m, INT_MAX));

    q.push({0, {0, 0}});

    dist[0][0] = 0;

    int delX[] = {-1, 1, 0, 0};

    int delY[] = {0, 0, -1, 1};

    while (!q.empty())
    {

        int effort = q.top().first;

        int i = q.top().second.first;

        int j = q.top().second.second;

        q.pop();

        // -------------------------------------------------------
        // Destination Reached
        // -------------------------------------------------------

        if (i == n - 1 && j == m - 1)

            return effort;

        for (int k = 0; k < 4; k++)
        {

            int row = i + delX[k];

            int col = j + delY[k];

            if (row >= 0 &&
                col >= 0 &&
                row < n &&
                col < m)
            {

                int newEffort =
                    max(
                        effort,
                        abs(
                            heights[row][col] -
                            heights[i][j]));

                if (newEffort < dist[row][col])
                {

                    dist[row][col] = newEffort;

                    q.push({max(
                                effort,
                                abs(
                                    heights[row][col] -
                                    heights[i][j])),
                            {row, col}});
                }
            }
        }
    }

    return -1;
}

// ===============================================================
// Main
// ===============================================================

int main()
{

    vector<vector<int>> heights =
        {
            {1, 2, 2},
            {3, 8, 2},
            {5, 3, 5}};

    cout << "Minimum Effort : "
         << minimumEffortPath(heights);

    return 0;
}