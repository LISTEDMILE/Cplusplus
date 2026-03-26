#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stack>

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

    stack<int> FindTopologicalOrder()
    {
        stack<int> s;
        vector<bool> visited(Size, false);
        TopologicalOrder(visited, s, 0);
        return s;
    }

    void TopologicalOrder(vector<bool> visited, stack<int> &s, int u)
    {
        // dekho topolocial order ka matlab h ki if u -> v h graph me to u hmesha v se pehle aaega poore sequence me to jitne bhi u->v h sab u apne apne v se pehle aaenge....

        // ab isme condition h ki cyclic agar hoga to possible hi nhi h
        // aur directed bhi hona chahiye graph

        // ab hmne simple dfs wala hi logic apnaya par hme u -> v jare to aisa kya kare ki dekho hmko kya chahiye pehle u fir v ka badme dekhenge print ho aur ye bhi dekhenge ki a->v bhi ho to v a aur u dono ke bad aae
        // uske liye hm pehle sab recursion complete kar lenge fir apne u ko push karenge stack me isse apna u sabse uper hoga matlab ye to pakka h ki u -> v h to u v ke to uper hi rhega fir v -> a to agla recursion make sure karenge ki v a se uper rhe aise karke perfect stack milega......

        // hme basically ek seq bnana jisme agar u => v h to u v se pehle hi aae........

        visited[u] = true;
        for (int val : l[u])
        {
            if (!visited[val])
            {
                TopologicalOrder(visited, s, val);
            }
        }

        s.push(u);
    }
};

int main()
{
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    if (g.DetectCycleDirectedGraph())
        cout << "The graph has cycle";
    else
    {
        cout << "Order : ";
        stack<int> s = g.FindTopologicalOrder();
        while (!s.empty())
        {
            cout << s.top() << ' ';
            s.pop();
        }
    }

    return 0;
}