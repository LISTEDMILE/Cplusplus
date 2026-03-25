#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

int timeToRot(vector<vector<int>> &grid)
{

    // dekho ek grid h jisme 3 no h 1,0,2
    // 0 ka mtlab kuch nhi h
    // 1 matlab tomato h fresh
    // 2 matlab tomato h rotten

    // ab agar rotten ke pas fresh rakhe to ek unit time me fresh bhi rot ho jaega
    /// to hme wo max time btana h jisme jitne bhi rote hone possible h sare ho jaenge
    // kyoki ek rot hua fir wo apne padosi ko rot karega to 2 unit time ho gya

    // ab hmne kya kiya pehle ek q bnai aur usme sirf 2 yani rotten walo ki details store ki jisme h time,i,j
    // time abhi 0 and i j to iterators h jo position btare

    // ab jab bhi hmare ye rooten wale ko pop karenge visited me true karenge us position ko
    // aur fir check karenge uske sare padosi aur sabko q me push agar visited nhi h to
    // aur time + 1 karenge tab push karenge kyoki 1 unit time to gya usko rot karne me
    // ab jab is wale ke liye loop chalega matlab jab ye pop hoga same iske sare neighbour q me push visited true aur ye bhi nikalenge ki max time kya chalra h taki last me max ans aa ske.....

    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int maxTime = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({0, {i, j}});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        int time = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();
        maxTime = max(maxTime, time);

        if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1)
        {
            q.push({time + 1, {i - 1, j}});
            visited[i - 1][j] = true;
        }
        if (i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] == 1)
        {
            q.push({time + 1, {i + 1, j}});
            visited[i + 1][j] = true;
        }
        if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1)
        {
            q.push({time + 1, {i, j - 1}});
            visited[i][j - 1] = true;
        }
        if (j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] == 1)
        {
            q.push({time + 1, {i, j + 1}});
            visited[i][j + 1] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                return -1;
            }
        }
    }

    return maxTime;
}

int main()
{

    vector<vector<int>> grid = {
        {2, 1, 0, 1, 2},
        {1, 1, 1, 0, 0},
        {1, 1, 2, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1}};

    cout << "Max time to rot all : " << timeToRot(grid);

    return 0;
}