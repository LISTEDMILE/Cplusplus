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

void dijkstra(int src, vector<vector<Edge>> g, int v)
{

    vector<int> dist(v, INT16_MAX);
    dist[src] = 0;

    // // normal priority queue
    // priority_queue<int> q;
    // // reverse priority queue
    // priority_queue<int, vector<int>, greater<int>> q;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // <dist,v>
    q.push({0, src});
    while (!q.empty())
    {
        int vert = q.top().second;
        q.pop();

        for (Edge e : g[vert])
        {
            if (dist[e.v] > dist[vert] + e.weight)
            {
                dist[e.v] = dist[vert] + e.weight;

                q.push({dist[e.v], e.v});
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

    
    dijkstra(0, g, v);

    return 0;
}