#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

void findNoIs(vector<vector<bool>> &grid, vector<vector<bool>> &visited, int i, int j, int n, int m)
{
    // ab ye pehle 4 cond out of bound grid se bahar pointer jae to
    // fir visited agar h pehle hi to
    // fir kahi pointer pe 0 yani water to nhi inme se kuch bhi hua to return

    // nhi to visited true karenge taki ispe dobara na aae
    // fir same kam uske left right top bottom pe karenge taki dekh sake neighbour same island ka part h kya agar ha to recursion se visited true ho jae aur main fn me ignore ho wo....

    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == true || grid[i][j] != true)
        return;

    visited[i][j] = true;

    findNoIs(grid, visited, i, j + 1, n, m); // right
    findNoIs(grid, visited, i + 1, j, n, m); // bottom
    findNoIs(grid, visited, i - 1, j, n, m); // left
    findNoIs(grid, visited, i, j - 1, n, m); // top
}
int findNoOfIslands(vector<vector<bool>> &grid)
{

    // dekho hme kya karna ek grid di hui h jisme 1 and 0 h matlab 1 h to land and 0 h to water ab hme btana h no of islands
    // matlab hme btana h no of groups of one kyuki ek ass pas ke sare 1s judke ek island bnaenge ..

    // ab hmne kya kiya sabse pehle ek ek karke 1 ko dhoondna chalu kiya poore grid me nested loop lgake
    // jha hme pehle 1 mila to agar wo pehle hi visited h to matlab wo ho gya count uska grp nhi to
    // ab uske liye fn call karenge jo uske poore grp ko just visited karke dedega mtlb simply hmne wo aur uska poora grp sabko visited kar diya taki next iterations me wo count na ho aur simply apna jo island cout h jo ans h usme ek plus kiya is wale grp ko ans me add karne ke liye....

    int n = grid.size();    // no of rows
    int m = grid[0].size(); // no of columns
    int ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == true && visited[i][j] != true)
            {
                findNoIs(grid, visited, i, j, n, m);
                ans++;
            }
        }
    }
    return ans;
}

int main()
{

    vector<vector<bool>> grid = {
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1}};

    cout << "No of Islands : " << findNoOfIslands(grid);

    return 0;
}