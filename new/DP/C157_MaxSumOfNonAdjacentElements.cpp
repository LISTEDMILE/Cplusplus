#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int calcSum(vector<int> &arr, int n) //  t -> O(2^n)
{
    if (n == 0)
        return arr[0];

    int pick = arr[n];
    if (n > 1)
        pick = arr[n] + calcSum(arr, n - 2);
    int notPick = calcSum(arr, n - 1);

    return max(pick, notPick);
}

int calcSumOptimal(vector<int> &arr, int n, unordered_map<int, int> &m) // S -> O(n) + O(n) t -> O(n)
{
    if (n == 0)
        return arr[0];

    if (m.find(n) != m.end())
        return m[n];

    int pick = arr[n];
    if (n > 1)
        pick = arr[n] + calcSumOptimal(arr, n - 2, m);
    int notPick = calcSumOptimal(arr, n - 1, m);

    return m[n] = max(pick, notPick);
}

int calcSumMostOptimal(vector<int> &arr) // S -> O(n)  t -> O(n)
{
    vector<int> dp(arr.size(), -1);
    dp[0] = arr[0];
    if (arr.size() == 1)
        return (arr[0]);

    dp[1] = max(dp[0], arr[1]);
    for (int i = 2; i < arr.size(); i++)
    {

        int take = arr[i] + dp[i - 2];
        int noTake = dp[i - 1];

        dp[i] = max(take, noTake);
    }
    return dp[arr.size() - 1];
}

int calcSumMostMostOptimal(vector<int> &arr)
{ // S -> O(1) t -> O(n)
    int prev = arr[0];
    int prev2 = 0;
    int currI = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        int take = arr[i] + prev2;
        int noTake = prev;

        currI = max(take, noTake);
        prev2 = prev;
        prev = currI;
    }
    return currI;
}

int maxSumOptimal(vector<int> &arr)
{
    unordered_map<int, int> m;
    return calcSumOptimal(arr, arr.size() - 1, m);
}

int main()
{
    vector<int> arr = {1, 2, 4, 2, 3, 5};

    cout << calcSum(arr, arr.size() - 1) << endl;

    cout << maxSumOptimal(arr) << endl;

    cout << calcSumMostOptimal(arr) << endl;

    cout << calcSumMostMostOptimal(arr) << endl;
    return 0;
}