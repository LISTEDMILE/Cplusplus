#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

bool DetectCycleDfs(int src, vector<vector<int>> &edges, vector<int> &visited, vector<int> &recPath)
{
    visited[src] = true;
    recPath[src] = true;

    for (int i = 0; i < edges.size(); i++)
    {
        int v = edges[i][0]; // for this
        int u = edges[i][1]; // this is needed

        if (src == u)
        {
            if (!visited[v])
            {
                if (DetectCycleDfs(v, edges, visited, recPath))
                {
                    return true;
                }
            }
            else if (recPath[v])
            {
                return true;
            }
        }
    }
    recPath[src] = false;
    return false;
}

void topoOrder(int src, vector<vector<int>> &edges, vector<int> &visited, stack<int> &s)
{
    visited[src] = true;

    for (int i = 0; i < edges.size(); i++)
    {
        int v = edges[i][0]; // for this
        int u = edges[i][1]; // this is needed

        if (src == u)
        {
            topoOrder(v, edges, visited, s);
        }
    }

    s.push(src);
}

vector<int> findOrder(int n, vector<vector<int>> &edges)
{

    // dekho pehle to same hm check karenge kya poosible h nhi to [] return
    // agar poosible h yani koi cycle nhi h to topologicl sort();

    // uske liye bhi most same hi h dfs wala logic jo poosible h ya nhi check karne ke liye use kiya
    // par is bar agar src mile to seedha rec se topoOrder ko call karenge aur s me push karenge  taki usko reverse me dekh ske aur isko array me dalke return ;;;;

    vector<int> visited(n, false);
    vector<int> recPath(n, false);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (DetectCycleDfs(i, edges, visited, recPath))
            {
                return ans;
            }
        }
    }

    // topological order
    stack<int> s;
    visited.assign(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoOrder(i, edges, visited, s);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    int n = 4;

    vector<vector<int>> preRequisits = {
        {1, 0}, // 0 → 1
        {2, 1}, // 1 → 2
        {3, 2}  // 2 → 3
    };

    cout << "Schedule : ";
    for (int val : findOrder(4, preRequisits))
    {
        cout << val << " ";
    }

    return 0;
}