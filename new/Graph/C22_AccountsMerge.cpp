#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ===============================================================
// Accounts Merge
// (Disjoint Set Union - Union by Size)
// ===============================================================
//
// Each account contains:
//
// accounts[i][0] -> Name
// accounts[i][1...] -> Emails
//
// If two accounts contain the same email,
// they belong to the same person and must
// be merged.
//
// Idea:
//
// 1. Consider every account index as a DSU node.
//
// 2. Store:
//
//      email -> account index
//
//    inside an unordered_map.
//
// 3. If an email appears for the first time,
//    map it to the current account.
//
// 4. If the same email appears again,
//    union the current account with the
//    previously stored account.
//
// 5. After all unions are completed,
//    find the ultimate parent of every email
//    and place the email inside that parent's
//    group.
//
// 6. Sort the emails and add the account name.
//
// Time Complexity : O(N × M × α(N) + E log E)
//
// Space Complexity : O(N + E)
// ===============================================================

// ---------------------------------------------------------------
// Find Ultimate Parent
// Path Compression
// ---------------------------------------------------------------

int findPar(int u, vector<int> &par)
{
    if (par[u] == u)

        return u;

    return par[u] = findPar(par[u], par);
}

// ---------------------------------------------------------------
// Union by Size
// ---------------------------------------------------------------

void unionBySize(int u,
                 int v,
                 vector<int> &par,
                 vector<int> &size)
{
    int parU = findPar(u, par);

    int parV = findPar(v, par);

    if (parU == parV)

        return;

    if (size[parU] > size[parV])
    {
        par[parV] = parU;

        size[parU] += size[parV];
    }
    else
    {
        par[parU] = parV;

        size[parV] += size[parU];
    }
}

// ---------------------------------------------------------------
// Accounts Merge
// ---------------------------------------------------------------

vector<vector<string>> accountsMerge(
    vector<vector<string>> &accounts)
{
    unordered_map<string, int> m;

    int n = accounts.size();

    vector<int> size(n, 1);

    vector<int> par(n);

    for (int i = 0; i < n; i++)

        par[i] = i;

    // -----------------------------------------------------------
    // Map Emails and Merge Accounts
    // -----------------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            if (m.find(accounts[i][j]) == m.end())
            {
                m[accounts[i][j]] = i;
            }
            else
            {
                unionBySize(
                    i,
                    m[accounts[i][j]],
                    par,
                    size);
            }
        }
    }

    // -----------------------------------------------------------
    // Put Emails Under Their Ultimate Parent
    // -----------------------------------------------------------

    vector<vector<string>> temp(n);

    for (auto &it : m)
    {
        string key = it.first;

        int ulPar =
            findPar(it.second, par);

        temp[ulPar].push_back(key);
    }

    // -----------------------------------------------------------
    // Build Final Answer
    // -----------------------------------------------------------

    vector<vector<string>> ans;

    for (int i = 0; i < n; i++)
    {
        if (!temp[i].empty())
        {
            sort(
                temp[i].begin(),
                temp[i].end());

            vector<string> oneTime;

            oneTime.push_back(
                accounts[i][0]);

            for (auto it : temp[i])

                oneTime.push_back(it);

            ans.push_back(oneTime);
        }
    }

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<vector<string>> accounts =
        {
            {"John",
             "johnsmith@mail.com",
             "john_newyork@mail.com"},
            {"John",
             "johnsmith@mail.com",
             "john00@mail.com"},
            {"Mary",
             "mary@mail.com"},
            {"John",
             "johnnybravo@mail.com"}};

    vector<vector<string>> ans =
        accountsMerge(accounts);

    cout << "Merged Accounts :\n\n";

    for (auto &account : ans)
    {
        for (auto &it : account)

            cout << it << " ";

        cout << endl;
    }

    return 0;
}