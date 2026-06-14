#include <iostream>
#include <vector>

using namespace std;
// we have to tell ki koi grid ya matrix ke kisi place pe hm kitne ways se pohoch skte h 00 se condition is ki sirf bottom ya right ja skte h
// isko halka badalke hm i,j se 0,0 tak jaenge....

int uniquePath(int row, int col)
{
    if (row == 0 && col == 0)
    {
        return 1;
    }
    if (row < 0 || col < 0)
    {
        return 0;
    }

    int up = uniquePath(row - 1, col);
    int left = uniquePath(row, col - 1);

    return up + left;
}

int uniquePathOptimalMemoization(int row, int col, vector<vector<int>> &p)
{
    if (row == 0 && col == 0)
    {
        return 1;
    }
    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (p[row][col] != -1)
        return p[row][col];
    int up = uniquePathOptimalMemoization(row - 1, col, p);
    int left = uniquePathOptimalMemoization(row, col - 1, p);

    return p[row][col] = up + left;
}

// this time we will move from 00 and check ki pref me kitne ways the left me aur up me dono ko app karenge to curr ke ways aa jaenge...
int uniquePathOptimalTabulation(int row, int col, vector<vector<int>> &p)
{
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            if (i == 0 && j == 0)
            {
                p[i][j] = 1;
            }
            else
            {
                int left = 0;
                int up = 0;
                if (i > 0)
                {
                    up = p[i - 1][j];
                }
                if (j > 0)
                {
                    left = p[i][j - 1];
                }
                p[i][j] = left + up;
            }
        }
    }
    return p[row][col];
}

int uniquePathMostOptimized(int row, int col)
{
    vector<int> prev(col + 1, 0);
    for (int i = 0; i <= row; i++)
    {
        vector<int> temp(col + 1, 0);
        for (int j = 0; j <= col; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[0] = 1;
            }
            else
            {
                if (j == 0)
                {
                    temp[j] = prev[j];
                }
                else
                {
                    temp[j] = prev[j] + temp[j - 1];
                }
            }
        }
        prev = temp;
    }
    return prev[col];
}

int main()
{

    int i = 6;
    int j = 5;

    cout << "No. of unique paths : " << uniquePath(i, j);

    vector<vector<int>> p(i + 1, vector<int>(j + 1, -1));

    cout << "\nNo. of unique paths (Optimal) : " << uniquePathOptimalMemoization(i, j, p);

    p = vector<vector<int>>(i + 1, vector<int>(j + 1, -1));

    cout << "\nNo. of unique paths (Tabulation) : " << uniquePathOptimalTabulation(i, j, p);

    cout << "\nNo. of unique paths (Most Optimized) : " << uniquePathMostOptimized(i, j);

    return 0;
}