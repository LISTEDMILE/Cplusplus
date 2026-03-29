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

    vector<int> topoSort()
    {
        // kuch nhi hme ab topological order nikalna h valid
        // hmne sbse pehle jitne nodes h sabki indeg yani kitne node ek node ko point karte h uska array create kiya..
        // uske bad  jo jo bhi 0 wale h malab jine koi point nhi karta ab cycle nhi h to ek na ek to aisa hoga hi to 0 walo ko queue me push kiya....
        // ab jab tak queue empty nhi hoti ek ek ko pop front kiyaans me push kiya aur is index pe jitne bhi point karta h ye sabki indeg -- ki aur check agar 0 ho gyi to uska ab q me push  ..
        // last me check karliya ki arr ka size nodes ke size ka h na matlab ans ka size jitne node the utna h to thik h warna fir cycle thii.....
        queue<int> q;
        vector<int> indeg(Size, 0);
        vector<int> ans;

        for (int i = 0; i < Size; i++)
        {
            for (int val : l[i])
            {
                indeg[val]++;
            }
        }

        for (int i = 0; i < Size; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (int val : l[curr])
            {
                indeg[val]--;
                if (indeg[val] == 0)
                {
                    q.push(val);
                }
            }
        }
        if (ans.size() == Size)
            return ans;
        return vector<int>();
    }
};
int main()
{
    // 🔹 Example 1: No cycle
    Graph g1(6);

    g1.addEdge(5, 2);
    g1.addEdge(5, 0);
    g1.addEdge(4, 0);
    g1.addEdge(4, 1);
    g1.addEdge(2, 3);
    g1.addEdge(3, 1);

    vector<int> topo1 = g1.topoSort();

    cout << "Test 1 (No Cycle):\n";
    if (!topo1.empty())
    {
        cout << "Topological Order: ";
        for (int x : topo1)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Cycle detected\n";
    }

    cout << endl;

    // 🔹 Example 2: Cycle present
    Graph g2(3);

    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0); // cycle

    vector<int> topo2 = g2.topoSort();

    cout << "Test 2 (Cycle):\n";
    if (!topo2.empty())
    {
        cout << "Topological Order: ";
        for (int x : topo2)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Cycle detected\n";
    }

    return 0;
}