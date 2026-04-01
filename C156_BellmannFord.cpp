#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
    int v;
    int weight;

    Edge(int v, int weight)
    {
        this->v = v;
        this->weight = weight;
    }
};

void BellmanFord(int src, vector<vector<Edge>> g, int v)
{

    vector<int> dist(v, INT16_MAX);
    dist[src] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        for (int u = 0; u < v; u++)
        {
            for (Edge e : g[u])
            {
                if (dist[e.v] > dist[u] + e.weight)
                {
                    dist[e.v] = dist[u] + e.weight;
                }
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << dist[i] << " " << endl;
    }
}

int main()
{

    int v = 6;
    vector<vector<Edge>> g(v);
    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[4].push_back(Edge(3, 2));
    g[3].push_back(Edge(5, 1));

    BellmanFord(0, g, v);

    return 0;
}