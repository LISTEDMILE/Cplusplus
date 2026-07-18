#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ===============================================================
// 01 Matrix
// ===============================================================
//
// We are given a binary matrix.
//
// For every cell containing 1,
// find the distance to the nearest 0.
//
// We solve it using Multi-Source BFS.
//
// Instead of starting BFS from every 1,
// we start BFS simultaneously from all 0's.
//
// Time Complexity : O(N × M)
// Space Complexity : O(N × M)
// ===============================================================

// ===============================================================
// Approach 1 : Using Visited Array
// ===============================================================

vector<vector<int>> updateMatrixUsingVisited(vector<vector<int>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> ansMat(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<int, pair<int, int>>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({0, {i, j}});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {

        int dist = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;

        q.pop();

        ansMat[r][c] = dist;

        if (r + 1 < n && !visited[r + 1][c])
        {
            q.push({dist + 1, {r + 1, c}});
            visited[r + 1][c] = true;
        }

        if (r - 1 >= 0 && !visited[r - 1][c])
        {
            q.push({dist + 1, {r - 1, c}});
            visited[r - 1][c] = true;
        }

        if (c + 1 < m && !visited[r][c + 1])
        {
            q.push({dist + 1, {r, c + 1}});
            visited[r][c + 1] = true;
        }

        if (c - 1 >= 0 && !visited[r][c - 1])
        {
            q.push({dist + 1, {r, c - 1}});
            visited[r][c - 1] = true;
        }
    }

    return ansMat;
}

// ===============================================================
// Approach 2 : Without Visited Array
// (Exactly Your Solution)
// ===============================================================

vector<vector<int>> updateMatrixWithoutVisited(vector<vector<int>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> ansMat(n, vector<int>(m, 0));
    queue<pair<int, pair<int, int>>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({0, {i, j}});
                mat[i][j] = 2;
            }
        }
    }

    while (!q.empty())
    {

        int dist = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;

        q.pop();

        ansMat[r][c] = dist;

        if (r + 1 < n && mat[r + 1][c] != 2)
        {
            q.push({dist + 1, {r + 1, c}});
            mat[r + 1][c] = 2;
        }

        if (r - 1 >= 0 && mat[r - 1][c] != 2)
        {
            q.push({dist + 1, {r - 1, c}});
            mat[r - 1][c] = 2;
        }

        if (c + 1 < m && mat[r][c + 1] != 2)
        {
            q.push({dist + 1, {r, c + 1}});
            mat[r][c + 1] = 2;
        }

        if (c - 1 >= 0 && mat[r][c - 1] != 2)
        {
            q.push({dist + 1, {r, c - 1}});
            mat[r][c - 1] = 2;
        }
    }

    return ansMat;
}

// ===============================================================
// Print Matrix
// ===============================================================

void printMatrix(vector<vector<int>> &mat)
{

    for (auto &row : mat)
    {

        for (int val : row)
            cout << val << " ";

        cout << endl;
    }
}

// ===============================================================
// Main
// ===============================================================

int main()
{

    vector<vector<int>> mat =
        {
            {0, 0, 0},
            {0, 1, 0},
            {1, 1, 1}};

    vector<vector<int>> copyMat = mat;

    cout << "Using Visited Array" << endl;

    vector<vector<int>> ans1 = updateMatrixUsingVisited(mat);

    printMatrix(ans1);

    cout << endl;

    cout << "Without Visited Array" << endl;

    vector<vector<int>> ans2 = updateMatrixWithoutVisited(copyMat);

    printMatrix(ans2);

    return 0;
}