#include <iostream>
#include <vector>

using namespace std;

// ===============================================================
// Disjoint Set Union (Union by Size + Path Compression)
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
// • Union by Size
//      Always attaches the smaller component under
//      the larger component.
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

    vector<int> sizeOf;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);

        sizeOf.resize(n + 1, 1);

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
    // Union by Size
    // -----------------------------------------------------------

    void Union(int u, int v)
    {
        int parU = find(u);

        int parV = find(v);

        if (parU == parV)

            return;

        if (sizeOf[parU] > sizeOf[parV])
        {
            parent[parV] = parU;

            sizeOf[parU] += sizeOf[parV];
        }
        else
        {
            parent[parU] = parV;

            sizeOf[parV] += sizeOf[parU];
        }
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