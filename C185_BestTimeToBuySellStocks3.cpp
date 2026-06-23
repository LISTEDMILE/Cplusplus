#include <iostream>
#include <vector>

using namespace std;

// We can perform at most
// two transactions.
//
// State:
//
// idx
// Current day.
//
// buy = 1
// We are allowed to buy.
//
// buy = 0
// We currently own a stock
// and are allowed to sell.
//
// cap
// Number of transactions remaining.
//
// At every state,
// either perform the action
// or skip the current day.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int stockBuySell(int idx,
                 int buy,
                 int cap,
                 vector<int> &prices,
                 int n)
{
    if (idx == n || cap == 0)
        return 0;

    if (buy)
    {
        return max(
            -prices[idx] +
                stockBuySell(idx + 1,
                             0,
                             cap,
                             prices,
                             n),

            stockBuySell(idx + 1,
                         1,
                         cap,
                         prices,
                         n));
    }

    return max(
        prices[idx] +
            stockBuySell(idx + 1,
                         1,
                         cap - 1,
                         prices,
                         n),

        stockBuySell(idx + 1,
                     0,
                     cap,
                     prices,
                     n));
}

int maxProfit(vector<int> &prices)
{
    return stockBuySell(0,
                        1,
                        2,
                        prices,
                        prices.size());
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int stockBuySellOptimalMemoization(
    int idx,
    int buy,
    int cap,
    vector<int> &prices,
    int n,
    vector<vector<vector<int>>> &dp)
{
    if (idx == n || cap == 0)
        return 0;

    if (dp[idx][buy][cap] != -1)
        return dp[idx][buy][cap];

    if (buy)
    {
        return dp[idx][buy][cap] =
                   max(
                       -prices[idx] +
                           stockBuySellOptimalMemoization(
                               idx + 1,
                               0,
                               cap,
                               prices,
                               n,
                               dp),

                       stockBuySellOptimalMemoization(
                           idx + 1,
                           1,
                           cap,
                           prices,
                           n,
                           dp));
    }

    return dp[idx][buy][cap] =
               max(
                   prices[idx] +
                       stockBuySellOptimalMemoization(
                           idx + 1,
                           1,
                           cap - 1,
                           prices,
                           n,
                           dp),

                   stockBuySellOptimalMemoization(
                       idx + 1,
                       0,
                       cap,
                       prices,
                       n,
                       dp));
}

int maxProfitOptimalMemoization(
    vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n,
        vector<vector<int>>(
            2,
            vector<int>(3, -1)));

    return stockBuySellOptimalMemoization(
        0,
        1,
        2,
        prices,
        n,
        dp);
}

// ---------------------------------------------------------------
// Tabulation
// ---------------------------------------------------------------

int maxProfitOptimalTabulation(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(2, vector<int>(3, 0)));

    // -----------------------------
    // Base Case 1:
    // If no days are left (idx == n),
    // profit is 0 irrespective of
    // buy state and transactions left.
    // -----------------------------
    for (int buy = 0; buy <= 1; buy++)
    {
        for (int cap = 0; cap <= 2; cap++)
        {
            dp[n][buy][cap] = 0;
        }
    }

    // -----------------------------
    // Base Case 2:
    // If no transactions are left,
    // profit is 0 irrespective of
    // day and buy state.
    // -----------------------------
    for (int idx = 0; idx <= n; idx++)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            dp[idx][buy][0] = 0;
        }
    }

    // Fill DP table
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                {
                    dp[idx][buy][cap] =
                        max(-prices[idx] + dp[idx + 1][0][cap],
                            dp[idx + 1][1][cap]);
                }
                else
                {
                    dp[idx][buy][cap] =
                        max(prices[idx] + dp[idx + 1][1][cap - 1],
                            dp[idx + 1][0][cap]);
                }
            }
        }
    }

    return dp[0][1][2];
}

int maxProfitMostOptimized(vector<int> &prices)
{
    int n = prices.size();

    // Base Case:
    // idx == n
    // profit = 0 for every buy state
    // and every transaction count.

    vector<vector<int>> dp(2, vector<int>(3, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<vector<int>> temp(2, vector<int>(3, 0));

        // Base Case:
        // cap == 0
        // profit = 0
        temp[0][0] = 0;
        temp[1][0] = 0;

        for (int cap = 1; cap <= 2; cap++)
        {
            // Sell State (buy = 0)
            temp[0][cap] =
                max(prices[idx] + dp[1][cap - 1],
                    dp[0][cap]);

            // Buy State (buy = 1)
            temp[1][cap] =
                max(-prices[idx] + dp[0][cap],
                    dp[1][cap]);
        }

        dp = temp;
    }

    return dp[1][2];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << "Maximum Profit (Recursion) : "
         << maxProfit(prices);

    cout << "\nMaximum Profit (Memoization) : "
         << maxProfitOptimalMemoization(prices);

    cout << "\nMaximum Profit (Tabulation) : "
         << maxProfitOptimalTabulation(prices);

    cout << "\nMaximum Profit (Most Optimized) : "
         << maxProfitMostOptimized(prices);

    return 0;
}