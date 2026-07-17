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

    void DepthFirstSearch()
    {
        vector<bool> visited(Size, false);
        DepthFirstSearchHelper(0, visited);
    }

    void DepthFirstSearchHelper(int u, vector<bool> &visited)
    {
        /// yha pe ek bar jo vertex liya uska print karenge fir uske sare neighbours pe dfs recursion karte karte last tak pohochenge fir usko print karenge fir backtrack karenge....
        cout << " " << u;
        visited[u] = true;
        for (int val : l[u])
        {
            if (!visited[val])
            {
                DepthFirstSearchHelper(val, visited);
            }
        }
    }
};

int main()
{

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(2, 5);
    g.addEdge(1, 4);
    g.addEdge(3, 2);

    g.DepthFirstSearch();

    return 0;
}