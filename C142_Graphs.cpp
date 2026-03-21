// list in c++ is implememted in stl by dll
#include <iostream>
#include <list>

using namespace std;

// see hmne pehle constructor se ek arr of list create ki arr ka size is the graph
// l = list of list
// ab jo vertex h wo h index of l
// aur index i pe list me jo jo bhi h wo h i vertex ke neighbours.....
class Graph
{
    int Size;
    list<int> *l;

public:
    Graph(int val)
    {
        this->Size = val;
        l = new list<int>[Size]; // is line ka matlab dekho
        // list<int> *l matlab l is a list
        // ab usme hmne elments kya dlae list<int>[Size] matlab list<int> element dale Size bar....
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
};

int main()
{
    // implementation using list (undirected unweighted graph)
    // list me index is the vertex and the value on index i is a list of vretices which are connected to i

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(2, 5);
    g.addEdge(1, 4);
    g.addEdge(3, 2);

    g.printEdges();

    return 0;
}