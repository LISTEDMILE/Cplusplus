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

    bool DetectCycleDirectedGraph()
    {
        vector<bool> visited(Size, false);
        vector<bool> recurPath(Size, false);
        for (int i = 0; i < Size; i++)
        {
            if (!visited[i])
            {
                if (DetectCycleDirectedDFS(i, visited, recurPath))
                    return true;
            }
        }
        return false;
    }

    bool DetectCycleDirectedDFS(int u, vector<bool> &visited, vector<bool> &recurPath)
    {
        visited[u] = true;
        recurPath[u] = true;

        for (int val : l[u])
        {
            if (!visited[val])
            {
                if (DetectCycleDirectedDFS(val, visited, recurPath))
                    return true;
            }
            else if (recurPath[val])
                return true;
        }

        recurPath[u] = false;
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

    if (g.DetectCycleDirectedGraph())
        cout << "The graph has cycle";
    else
        cout << "The graph has no cycle";

    return 0;
}