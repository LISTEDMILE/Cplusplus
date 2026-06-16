#include <iostream>
#include <vector>

using namespace std;

// Given an array and a target.
//
// Determine whether there exists a subset
// whose sum equals the target.
//
// State:
// dp[i][target]
//
// i      -> Current Index
// target -> Remaining Sum

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

bool subsetSum(int i, int target, vector<int> &arr)
{

    if (arr[i] == target)
        return true;

    if (i == 0)
    {
        return (arr[0] == target);
    }

    bool take = false;
    if (arr[i] <= target)
        take = subsetSum(i - 1, target - arr[i], arr);

    bool notTake = subsetSum(i - 1, target, arr);

    return take || notTake;
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

bool subsetSumMemo(int i, int target, vector<int> &arr,
                   vector<vector<int>> &dp)
{
    if (arr[i] == target)
        return true;

    if (i == 0)
    {
        return (arr[0] == target);
    }

    if (dp[i][target] != -1)
        return dp[i][target];

    bool take = false;
    if (arr[i] <= target)
        take = subsetSum(i - 1, target - arr[i], arr);

    bool notTake = subsetSum(i - 1, target, arr);

    return dp[i][target] = take || notTake;
}

// ---------------------------------------------------------------
// Tabulation
//
// Base Case:
// target = 0 is always possible.
// ---------------------------------------------------------------

bool subsetSumTabulation(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n,
                            vector<bool>(target + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {

            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
            {
                take = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = take || notTake;
        }
    }
    return dp[n - 1][target];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Every row depends only on previous row.
// ---------------------------------------------------------------

bool subsetSumMostOptimized(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<bool> prev(target + 1, false);

    prev[0] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> temp(target + 1, false);
        temp[0] = true;
        for (int j = 1; j <= target; j++)
        {

            bool notTake = prev[j];
            bool take = false;
            if (arr[i] <= j)
            {
                take = prev[j - arr[i]];
            }

            temp[j] = take || notTake;
        }
        prev = temp;
    }
    return prev[target];
}

// some extra optimization from me
// if at first iteration on target idx i found true then why should i fill whole matrix...

bool subsetSumMostOptimizedExtraByMe(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<bool> prev(target + 1, false);

    prev[0] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> temp(target + 1, false);
        temp[0] = true;
        for (int j = 1; j <= target; j++)
        {

            bool notTake = prev[j];
            bool take = false;
            if (arr[i] <= j)
            {
                take = prev[j - arr[i]];
            }

            temp[j] = take || notTake;
        }
        if (temp[target])
            return true;

        prev = temp;
    }
    return prev[target];
}

// ---------------------------------------------------------------

int main()
{
    vector<int> arr = {2, 3, 7, 8, 10};

    int target = 11;

    int n = arr.size();

    cout << "Subset Sum (Recursion) : "
         << (subsetSum(n - 1, target, arr) ? "Possible" : "Not Possible");

    vector<vector<int>> dp(n,
                           vector<int>(target + 1, -1));

    cout << "\nSubset Sum (Memoization) : "
         << (subsetSumMemo(n - 1, target, arr, dp) ? "Possible" : "Not Possible");

    cout << "\nSubset Sum (Tabulation) : "
         << (subsetSumTabulation(arr, target) ? "Possible" : "Not Possible");

    cout << "\nSubset Sum (Most Optimized) : "
         << (subsetSumMostOptimized(arr, target) ? "Possible" : "Not Possible");

    cout << "\nSubset Sum (Most Optimized with own crazy(unused but ya for fun)) : "
         << (subsetSumMostOptimizedExtraByMe(arr, target) ? "Possible" : "Not Possible");

    return 0;
}