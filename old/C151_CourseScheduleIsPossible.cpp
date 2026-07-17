#include <iostream>
#include <list>
#include <queue>
#include <vector>

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

bool canPossible(int n, vector<vector<int>> &edges)
{
    // dekho ek array di hui h preRequisits ki jisme [u,v] malab v pehle complete hoga tabhi u kar skte h aise aise conditions di hui h hme btana h ki poora course complete ho bhi skta h ya nhi..
    /// to uske liye hm kya karenge ki jitne no. of courses ya kehlo hmne yha nodes of graph mana n h un sabke liye check kiya agar visited nhi h to unse koi cycle ban skti h

    // ab uske liye hr iteration me hmne ek aur loop se sbke liye u aur v nikala jisme u yani right side wal yani jispe v depend h wo src ke equal h yani jis node ke liye hm dhoond rhe h usme check karenge agar v visited hi nhi h to fir ab v ko src bnake check karenge rec se to agar aage v se cycle bni to seedha yha se return true..
    // nhi to ab check karenge matlab agar v visited h pehle se to dekhenge jo recPath hm maintain karrhe h matlab jab ek recursion cycle khatam to recPath [src] ko false karte chal rhe h taki like 0-1-2-3 gye to recPath 0,1,2,3 sabke liye true aur jaise jaise us rec se bahar aae ye false
    // to isme check karenge agar recPath true h to matlab v src ya u inke parents me kahi h to matalab pehle aa chuka h recursion path me matlab 0 1 2 3 1 matlab 1 pe cycle h.....

    vector<int> visited(n, false);
    vector<int> recPath(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (DetectCycleDfs(i, edges, visited, recPath))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 4;

    vector<vector<int>> preRequisits = {
        {1, 0}, // 0 → 1
        {2, 1}, // 1 → 2
        {3, 2}  // 2 → 3
    };

    if (canPossible(n, preRequisits))
    {
        cout << "Possible to complete all courses (No Cycle)" << endl;
    }
    else
    {
        cout << "Not possible (Cycle detected)" << endl;
    }

    return 0;
}