#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ===============================================================
// Find Eventual Safe States
// (BFS / Kahn's Algorithm)
// ===============================================================
//
// A node is called a Safe Node if
// every possible path starting from
// that node eventually reaches
// a terminal node.
//
// Idea:
//
// Reverse every edge.
//
// Original Edge
// u → v
//
// Reverse Edge
// v → u
//
// Compute indegree in the reversed graph.
//
// All terminal nodes in the original graph
// become nodes with indegree 0 in the
// reversed graph.
//
// Start Kahn's Algorithm from those nodes.
//
// Every node removed from the queue
// is a safe node.
//
// Finally sort the answer.
//
// Time Complexity : O(V + E)
//
// Space Complexity : O(V + E)
// ===============================================================

vector<int> safeNodes(vector<vector<int>> &edges,
                      int n,
                      int e)
{

    vector<vector<int>> adj(n);

    vector<int> ans;

    vector<int> indeg(n + 1, 0);

    queue<int> q;

    // -----------------------------------------------------------
    // Reverse the graph
    // -----------------------------------------------------------

    for (int i = 0; i < e; i++)
    {

        adj[edges[i][1]].push_back(edges[i][0]);

        indeg[edges[i][0]]++;
    }

    // -----------------------------------------------------------
    // Push all nodes having
    // indegree 0
    // -----------------------------------------------------------

    for (int i = 0; i < n; i++)
    {

        if (indeg[i] == 0)

            q.push(i);
    }

    // -----------------------------------------------------------
    // Kahn's Algorithm
    // -----------------------------------------------------------

    while (!q.empty())
    {

        int node = q.front();

        q.pop();

        ans.push_back(node);

        for (int it : adj[node])
        {

            indeg[it]--;

            if (indeg[it] == 0)

                q.push(it);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// ===============================================================
// Print Vector
// ===============================================================

void printVector(vector<int> &ans)
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

    int n = 7;

    vector<vector<int>> edges =
        {
            {0, 1},
            {0, 2},
            {1, 2},
            {1, 3},
            {2, 5},
            {3, 0},
            {4, 5}};

    int e = edges.size();

    vector<int> ans = safeNodes(edges, n, e);

    cout << "Safe Nodes : ";

    printVector(ans);

    return 0;
}