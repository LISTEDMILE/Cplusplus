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
                if (DetectCycleDFS(i, visited, -1))
                    return true;
            }
        }
        return false;
    }

    bool DetectCycleDFS(int u, vector<bool> &visited, int parent)
    {

        // dekho traverse to same dfs ki tarah karenge but is bar na agar koi node ya val visited nhi h to uspe simple recursion se pta karenge ki usme cycle h ya nhi matlab simple recursion se call karenge and expect ki wo bta de usme cycle h ya nhi iske liye parent is bar ho jaega u matlab jo current node h
        // if visited nhi h to continue nhi karenge seedha check karenge kyoki agar wo pehle se visited h to do option h ya to wo whi node ho jisse hm yha tak pohoche h ya fir koi aur node ho jo pehle se visited h but is wale ka parent bhi nhi h wo to imagine a pair of 3 nodes a se b, b se c ab hm dekhre ki c se a bhi neighbour h to cycle h mtalb hm b pe h mano
        // check karenge b ke neighbour s
        // a visited h pehle to aur fir check karenge ki parent to nhi a to parent hi h to kuch nhi
        // b visited h ye bhi but ye parent nhi to matlab cycle h reutrn true......

        visited[u] = true;
        for (int val : l[u])
        {
            if (!visited[val])
            {
                if (DetectCycleDFS(val, visited, u))
                    return true;
            }
            else if (val != parent)
            {
                return true;
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