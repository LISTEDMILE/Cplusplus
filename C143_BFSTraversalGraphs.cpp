#include <iostream>
#include <list>
#include <queue>

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

    void BreadthFirstSearch()
    {
        // hmne kya kiya ek visited array bnai jisme sabhi abhi false kiye mtalb no visited
        // ek queue bnai q
        // ab at first 0th element of the graph jo hmne bnaya usko root me dala aur q me push kiya aur visited [0] ko true kiya yani ki 0th vertex visited
        // ab while loop me jo q pe front pe h pehle iteration me to 0 usko u me dala print kiya aur pop kraya
        // ab is u ke liye check karenge apni l list me ki isse kitne vertex connected h un sabko q me push karenge only if wo pehle se visited nhi aur unko visited kardenge...
        // aise hi har iteration me vertex print hoga aur usse connected vertex q me push honge....

        int root = 0;
        vector<bool> visited(Size, false);
        queue<int> q;
        q.push(root);
        visited[0] = true;
        while (!q.empty())
        {
            int u = q.front();
            cout << u << " ";
            q.pop();
            for (int val : l[u])
            {
                if (!visited[val])
                    q.push(val);
                visited[val] = true;
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

    g.BreadthFirstSearch();

    return 0;
}