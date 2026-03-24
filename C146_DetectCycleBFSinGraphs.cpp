#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
    int Size;
    list<int> *l;

public:
    Graph(int val)
    {
        this->Size = val;
        l = new list<int>[Size];
    }

    void addEdge(int vert1, int vert2)
    {
        l[vert1].push_back(vert2);
        l[vert2].push_back(vert1);
    }

    void printEdges()
    {
        for (int i = 0; i < Size; i++)
        {
            cout << i;
            for (int val : l[i])
            {
                cout << " -- " << val;
            }
            cout << "\n";
        }
    }

    bool DetectCycleUndirectedGraph()
    {
        vector<bool> visited(Size, false);
        for (int i = 0; i < Size; i++)
        {
            if (!visited[i])
            {
                if (DetectCycleBFS(i, visited))
                    return true;
            }
        }
        return false;
    }

    bool DetectCycleBFS(int u, vector<bool> &visited)
    {
        // yha bhi same whi karenge bfs use karke traverse par is bar q me pair me parent bhi maintain karenge cycle detection ke liye aur fir same tareeke se cycle detect karenge .....
        queue<pair<int, int>> q;
        q.push({u, -1});
        visited[u] = true;

        while (!q.empty())
        {
            int curr = q.front().first;
            int currParent = q.front().second;
            q.pop();

            for (int val : l[curr])
            {
                if (!visited[val])
                {
                    q.push({val, curr});
                    visited[val] = true;
                }

                else if (val != currParent)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g(7);

    // Component 1 (cycle)
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    // Component 2 (cycle)
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);

    // Node 6 isolated (optional extra test)

    if (g.DetectCycleUndirectedGraph())
        cout << "The graph has cycle";
    else
        cout << "The graph has no cycle";

    return 0;
}