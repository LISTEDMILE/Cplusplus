#include <iostream>
#include <vector>

using namespace std;

// We can buy and sell the stock
// any number of times.
//
// After selling a stock,
// we cannot buy on the next day.
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
// At every state,
// either perform the action
// or skip the current day.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int stockBuySell(int idx,
                 int buy,
                 vector<int> &prices,
                 int n)
{
    if (idx >= n)
        return 0;

    if (buy)
    {
        return max(
            -prices[idx] +
                stockBuySell(idx + 1,
                             0,
                             prices,
                             n),

            stockBuySell(idx + 1,
                         1,
                         prices,
                         n));
    }

    return max(
        prices[idx] +
            stockBuySell(idx + 2,
                         1,
                         prices,
                         n),

        stockBuySell(idx + 1,
                     0,
                     prices,
                     n));
}

int maxProfit(vector<int> &prices)
{
    return stockBuySell(
        0,
        1,
        prices,
        prices.size());
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int stockBuySellOptimalMemoization(
    int idx,
    int buy,
    vector<int> &prices,
    int n,
    vector<vector<int>> &dp)
{
    if (idx >= n)
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    if (buy)
    {
        return dp[idx][buy] =
                   max(
                       -prices[idx] +
                           stockBuySellOptimalMemoization(
                               idx + 1,
                               0,
                               prices,
                               n,
                               dp),

                       stockBuySellOptimalMemoization(
                           idx + 1,
                           1,
                           prices,
                           n,
                           dp));
    }

    return dp[idx][buy] =
               max(
                   prices[idx] +
                       stockBuySellOptimalMemoization(
                           idx + 2,
                           1,
                           prices,
                           n,
                           dp),

                   stockBuySellOptimalMemoization(
                       idx + 1,
                       0,
                       prices,
                       n,
                       dp));
}

int maxProfitOptimalMemoization(
    vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(
        n,
        vector<int>(2, -1));

    return stockBuySellOptimalMemoization(
        0,
        1,
        prices,
        n,
        dp);
}

// ---------------------------------------------------------------
// Tabulation
// ---------------------------------------------------------------

int maxProfitOptimalTabulation(
    vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(
        n + 2,
        vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        dp[idx][1] =
            max(
                -prices[idx] +
                    dp[idx + 1][0],

                dp[idx + 1][1]);

        dp[idx][0] =
            max(
                prices[idx] +
                    dp[idx + 2][1],

                dp[idx + 1][0]);
    }

    return dp[0][1];
}

// ---------------------------------------------------------------
// Space Optimization
//
// We need:
//
// dp       -> idx + 1
// prevPrev -> idx + 2
//
// Since after selling,
// we move to idx + 2 because
// of the cooldown day.
// ---------------------------------------------------------------

int maxProfitMostOptimized(
    vector<int> &prices)
{
    int n = prices.size();

    vector<int> dp(2, 0);
    vector<int> prevPrev(2, 0);
    vector<int> temp(2, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        // buy = 1

        temp[1] =
            max(
                -prices[idx] +
                    dp[0],

                dp[1]);

        // buy = 0

        temp[0] =
            max(
                prices[idx] +
                    prevPrev[1],

                dp[0]);

        prevPrev = dp;
        dp = temp;
    }

    return dp[1];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    vector<int> prices =
        {
            1, 2, 3, 0, 2};

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