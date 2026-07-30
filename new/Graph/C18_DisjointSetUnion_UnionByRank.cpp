#include <iostream>
#include <vector>

using namespace std;

// ===============================================================
// Disjoint Set Union (Union by Rank + Path Compression)
// ===============================================================
//
// Disjoint Set (DSU) is a data structure used to
// efficiently maintain a collection of disjoint sets.
//
// It supports two operations:
//
// 1. find(node)
//    -> Finds the Ultimate Parent (Representative)
//       of the set containing the node.
//
// 2. Union(u, v)
//    -> Merges the sets containing u and v.
//
// Optimizations:
//
// • Path Compression
//      Compresses the path during find() so that
//      future searches become faster.
//
// • Union by Rank
//      Always attaches the tree having smaller rank
//      under the tree having larger rank.
//
// Time Complexity:
//
// find()  : Nearly O(1)
// Union() : Nearly O(1)
//
// (More precisely O(α(N)),
// where α is the Inverse Ackermann Function.)
// ===============================================================

class DisjointSet
{
private:
    vector<int> parent;

    vector<int> rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);

        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // -----------------------------------------------------------
    // Find Ultimate Parent (Path Compression)
    // -----------------------------------------------------------

    int find(int node)
    {
        if (parent[node] == node)

            return node;

        return parent[node] = find(parent[node]);
    }

    // -----------------------------------------------------------
    // Union by Rank
    // -----------------------------------------------------------

    void Union(int u, int v)
    {
        int parU = find(u);

        int parV = find(v);

        if (parU == parV)

            return;

        if (rank[parU] == rank[parV])
        {
            parent[parV] = parU;

            rank[parU]++;

            return;
        }

        if (rank[parU] > rank[parV])
        {
            parent[parV] = parU;

            return;
        }

        parent[parU] = parV;
    }
};

// ===============================================================
// Main
// ===============================================================

int main()
{
    int n = 7;

    DisjointSet ds(n);

    // Create Components

    ds.Union(1, 2);

    ds.Union(2, 3);

    ds.Union(4, 5);

    ds.Union(6, 7);

    ds.Union(5, 6);

    if (ds.find(3) == ds.find(7))

        cout << "Same Component\n";

    else

        cout << "Different Components\n";

    // Merge Both Components

    ds.Union(3, 7);

    if (ds.find(3) == ds.find(7))

        cout << "Same Component\n";

    else

        cout << "Different Components\n";

    return 0;
}