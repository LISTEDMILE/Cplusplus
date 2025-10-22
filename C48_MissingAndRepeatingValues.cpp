#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> MissAnRepe(vector<vector<int>> arr)
{
    vector<int> ans;
    unordered_set<int> s;
    int n = arr.size();
    int a, b;

    int expectedSum = 0, actualSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            actualSum += arr[i][j];
            if (s.find(arr[i][j]) != s.end())
            {
                a = arr[i][j];
                ans.push_back(a);
            }
            s.insert(arr[i][j]);
        }
    }

    expectedSum = (n * n) * (n * n + 1) / 2; // sum of AP;
    b = expectedSum + a - actualSum;         // it is the actual missing value
    ans.push_back(b);
    return ans;
}

int main()
{

    vector<vector<int>> arr = {{2, 3, 1}, {4, 6, 9}, {9, 7, 8}};
    vector<int> ans = MissAnRepe(arr);
    for (int val : ans)
    {
        cout << val << " ";
    }
    return 0;
}