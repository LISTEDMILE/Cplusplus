#include <iostream>
#include <vector>

using namespace std;

// We can perform at most
// k transactions.
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

int maxProfit(int k,
              vector<int> &prices)
{
    return stockBuySell(
        0,
        1,
        k,
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
    int k,
    vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n,
        vector<vector<int>>(
            2,
            vector<int>(k + 1, -1)));

    return stockBuySellOptimalMemoization(
        0,
        1,
        k,
        prices,
        n,
        dp);
}

// ---------------------------------------------------------------
// Tabulation
// ---------------------------------------------------------------

int maxProfitOptimalTabulation(
    int k,
    vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(
            2,
            vector<int>(k + 1, 0)));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy)
                {
                    dp[idx][buy][cap] =
                        max(
                            -prices[idx] +
                                dp[idx + 1][0][cap],

                            dp[idx + 1][1][cap]);
                }
                else
                {
                    dp[idx][buy][cap] =
                        max(
                            prices[idx] +
                                dp[idx + 1][1][cap - 1],

                            dp[idx + 1][0][cap]);
                }
            }
        }
    }

    return dp[0][1][k];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Only the next day's state
// is required.
// ---------------------------------------------------------------

int maxProfitMostOptimized(
    int k,
    vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(
        2,
        vector<int>(k + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<vector<int>> temp(
            2,
            vector<int>(k + 1, 0));

        for (int cap = 1; cap <= k; cap++)
        {
            // buy = 0
            temp[0][cap] =
                max(prices[idx] +
                        dp[1][cap - 1],
                    dp[0][cap]);

            // buy = 1
            temp[1][cap] =
                max(-prices[idx] +
                        dp[0][cap],
                    dp[1][cap]);
        }

        dp = temp;
    }

    return dp[1][k];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    int k = 2;

    vector<int> prices =
        {
            3, 2, 6, 5, 0, 3};

    cout << "Maximum Profit (Recursion) : "
         << maxProfit(k, prices);

    cout << "\nMaximum Profit (Memoization) : "
         << maxProfitOptimalMemoization(k, prices);

    cout << "\nMaximum Profit (Tabulation) : "
         << maxProfitOptimalTabulation(k, prices);

    cout << "\nMaximum Profit (Most Optimized) : "
         << maxProfitMostOptimized(k, prices);

    return 0;
}