#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Path Compression
    int find(int node) {
        if(parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

   // Union by Rank
    void Union(int u, int v) {
        int parU = find(u);
        int parV = find(v);

        if(parU == parV)
            return;
        if(rank[parU] == rank[parV]){
            parent[parV] = parU;
            rank[parU]++;
            return;
        }
        if(rank[parU] >rank[parV]){
            parent[parV] = parU;
            return;
        }

        parent[parU] = parV;
    }
};

int main() {
    int n = 7;

    DisjointSet ds(n);

    // Test cases
    ds.Union(1, 2);
    ds.Union(2, 3);
    ds.Union(4, 5);
    ds.Union(6, 7);
    ds.Union(5, 6);

    if (ds.find(3) == ds.find(7))
        cout << "Same Component\n";
    else
        cout << "Different Components\n";

    ds.Union(3, 7);

    if (ds.find(3) == ds.find(7))
        cout << "Same Component\n";
    else
        cout << "Different Components\n";

    return 0;
}