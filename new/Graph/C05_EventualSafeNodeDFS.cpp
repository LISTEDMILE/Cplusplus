#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ===============================================================
// Find Eventual Safe States
// ===============================================================
//
// A node is called a Safe Node if
// every possible path starting from
// that node eventually reaches a
// terminal node.
//
// If a node is part of a cycle,
// or can reach a cycle,
// it is NOT a safe node.
//
// Idea:
//
// Perform DFS.
//
// visited      -> node has been visited.
//
// pathVisited  -> node is currently
//                 present in the DFS path.
//
// If during DFS we reach a node
// already present in the current path,
// then a cycle exists.
//
// Only after completely exploring
// a node without finding any cycle,
// we push it into the answer.
//
// Finally sort the answer.
//
// Time Complexity : O(V + E)
//
// Space Complexity : O(V)
// ===============================================================

bool helper(vector<vector<int>> &graph,
            vector<int> &visited,
            vector<int> &pathVisited,
            int idx,
            vector<int> &ans)
{

    visited[idx] = true;
    pathVisited[idx] = true;

    for (int it : graph[idx])
    {

        if (!visited[it])
        {

            if (helper(graph,
                       visited,
                       pathVisited,
                       it,
                       ans))
                return true;
        }

        else if (pathVisited[it])
            return true;
    }

    pathVisited[idx] = false;

    ans.push_back(idx);

    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{

    int n = graph.size();

    vector<int> visited(n, 0);

    vector<int> pathVisited(n, 0);

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {

            helper(graph,
                   visited,
                   pathVisited,
                   i,
                   ans);
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
    {

        cout << it << " ";
    }

    cout << endl;
}

// ===============================================================
// Main
// ===============================================================

int main()
{

    vector<vector<int>> graph =
        {
            {1, 2},
            {2, 3},
            {5},
            {0},
            {5},
            {},
            {}};

    vector<int> ans = eventualSafeNodes(graph);

    cout << "Safe Nodes : ";

    printVector(ans);

    return 0;
}