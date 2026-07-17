#include <iostream>
#include <vector>
#include <string>

using namespace std;

void findPath(vector<vector<bool>> &arr, int row, int col, int n, vector<string> &ans, string s, vector<vector<bool>> &tracked)
{
    if (row < 0 || col > n - 1 || row > n - 1 || col < 0 || !arr[row][col] || tracked[row][col])
    {
        return;
    }

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(s);
        return;
    }

    tracked[row][col] = true;

    findPath(arr, row + 1, col, n, ans, s + "D", tracked);
    findPath(arr, row - 1, col, n, ans, s + "U", tracked);
    findPath(arr, row, col + 1, n, ans, s + "R", tracked);
    findPath(arr, row, col - 1, n, ans, s + "L", tracked);

    tracked[row][col] = false;
}

vector<string> mazePath(vector<vector<bool>> &arr)
{
    int n = arr.size();
    vector<string> ans;
    vector<vector<bool>> tracked = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    findPath(arr, 0, 0, n, ans, "", tracked);
    return ans;
}

void findPathOptimized(vector<vector<bool>> &arr, int row, int col, int n, vector<string> &ans, string s)
{
    if (row < 0 || col > n - 1 || row > n - 1 || col < 0 || !arr[row][col])
    {
        return;
    }

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(s);
        return;
    }

    arr[row][col] = 0;

    findPathOptimized(arr, row + 1, col, n, ans, s + "D");
    findPathOptimized(arr, row - 1, col, n, ans, s + "U");
    findPathOptimized(arr, row, col + 1, n, ans, s + "R");
    findPathOptimized(arr, row, col - 1, n, ans, s + "L");

    arr[row][col] = 1;
}

vector<string> mazePathOptimized(vector<vector<bool>> &arr)
{
    int n = arr.size();
    vector<string> ans;

    findPathOptimized(arr, 0, 0, n, ans, "");
    return ans;
}

int main()
{
    vector<vector<bool>> arr = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = mazePath(arr);
    for (string val : ans)
    {
        for (char val1 : val)
        {
            cout << val1 << " -> ";
        }
        cout << "Final" << endl;
    }

    cout << endl;

    // both are almost same just in this we little enhanced the space complexity by removing tracked matrix but using the same arr assigning 0 to tracked in same insted of maintaining different matrix;....
    vector<vector<bool>> arrOptimized = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ansOptimized = mazePathOptimized(arr);
    for (string val : ansOptimized)
    {
        for (char val1 : val)
        {
            cout << val1 << " -> ";
        }
        cout << "Final" << endl;
    }
    return 0;
}