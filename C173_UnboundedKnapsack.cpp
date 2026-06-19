#include <iostream>
#include <vector>

using namespace std;

// We have n items.
//
// Every item has
// Weight
// Profit
//
// We have a bag of capacity W.
//
// Since every item can be taken
// infinite number of times,
// after taking an item
// we'll stay at the same index.
//
// State:
//
// dp[i][w]
// = Maximum profit using
// items from index 0 to i
// with remaining capacity w.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int unboundedKnapsack(int n,
                      int w,
                      vector<int> &profit,
                      vector<int> &weight)
{

    if (n == 0)
    {
        return (w / weight[0]) * profit[0];
    }

    int notTake = unboundedKnapsack(n - 1,
                                    w,
                                    profit,
                                    weight);

    int take = 0;

    if (w >= weight[n])
        take = profit[n] +
               unboundedKnapsack(n,
                                 w - weight[n],
                                 profit,
                                 weight);

    return max(take, notTake);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int unboundedKnapsackOptimalMemoization(int n,
                                        int w,
                                        vector<int> &profit,
                                        vector<int> &weight,
                                        vector<vector<int>> &dp)
{

    if (n == 0)
    {
        return (w / weight[0]) * profit[0];
    }

    if (dp[n][w] != -1)
        return dp[n][w];

    int notTake =
        unboundedKnapsackOptimalMemoization(n - 1,
                                            w,
                                            profit,
                                            weight,
                                            dp);

    int take = 0;

    if (w >= weight[n])
        take = profit[n] +
               unboundedKnapsackOptimalMemoization(n,
                                                   w - weight[n],
                                                   profit,
                                                   weight,
                                                   dp);

    return dp[n][w] = max(take, notTake);
}

// ---------------------------------------------------------------
// Tabulation
//
// We'll build the answer from
// index 0 to n-1.
//
// Since every item can be taken
// multiple times,
// while taking an item
// we'll stay in the same row.
// ---------------------------------------------------------------

int unboundedKnapsackOptimalTabulation(int n,
                                       int w,
                                       vector<int> &profit,
                                       vector<int> &weight)
{

    vector<vector<int>> dp(n,
                           vector<int>(w + 1, 0));

    // Base Case

    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = (i / weight[0]) * profit[0];
    }

    // Build Answer

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = dp[i - 1][j];

            int take = 0;

            if (j >= weight[i])
                take = dp[i][j - weight[i]] + profit[i];

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n - 1][w];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Since current row depends on
// previous row and current row,
// we'll use two arrays.
// ---------------------------------------------------------------

int unboundedKnapsackMostOptimized(int n,
                                   int w,
                                   vector<int> &profit,
                                   vector<int> &weight)
{

    vector<int> dp(w + 1, 0);

    // Base Case

    for (int i = 0; i <= w; i++)
    {
        dp[i] = (i / weight[0]) * profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(w + 1, 0);

        for (int j = 0; j <= w; j++)
        {
            int notTake = dp[j];

            int take = 0;

            if (j >= weight[i])
                take = temp[j - weight[i]] + profit[i];

            temp[j] = max(take, notTake);
        }

        dp = temp;
    }

    return dp[w];
}

// ---------------------------------------------------------------
// Even More Optimization
//
// Since current row depends upon
// itself, we can completely remove
// the temp array.
//
// This optimization is possible because
// it is an Unbounded Knapsack problem.
// ---------------------------------------------------------------

int unboundedKnapsackEvenMoreOptimized(int n,
                                       int w,
                                       vector<int> &profit,
                                       vector<int> &weight)
{

    vector<int> dp(w + 1, 0);

    // Base Case

    for (int i = 0; i <= w; i++)
    {
        dp[i] = (i / weight[0]) * profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = dp[j];

            int take = 0;

            if (j >= weight[i])
                take = dp[j - weight[i]] + profit[i];

            dp[j] = max(take, notTake);
        }
    }

    return dp[w];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    vector<int> profit = {5, 11, 13};
    vector<int> weight = {2, 4, 6};

    int n = profit.size();
    int w = 10;

    cout << "Maximum Profit (Recursion) : "
         << unboundedKnapsack(n - 1,
                              w,
                              profit,
                              weight);

    vector<vector<int>> memo(n,
                             vector<int>(w + 1, -1));

    cout << "\nMaximum Profit (Memoization) : "
         << unboundedKnapsackOptimalMemoization(n - 1,
                                                w,
                                                profit,
                                                weight,
                                                memo);

    cout << "\nMaximum Profit (Tabulation) : "
         << unboundedKnapsackOptimalTabulation(n,
                                               w,
                                               profit,
                                               weight);

    cout << "\nMaximum Profit (Most Optimized) : "
         << unboundedKnapsackMostOptimized(n,
                                           w,
                                           profit,
                                           weight);

    cout << "\nMaximum Profit (Even More Optimized) : "
         << unboundedKnapsackEvenMoreOptimized(n,
                                               w,
                                               profit,
                                               weight);

    return 0;
}