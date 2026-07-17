#include <iostream>
#include <vector>

using namespace std;

// We can buy and sell the stock
// any number of times.
//
// Every time we sell,
// we pay the transaction fee.
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
                 int fee,
                 int n)
{
    if (idx == n)
        return 0;

    if (buy)
    {
        return max(
            -prices[idx] +
                stockBuySell(idx + 1,
                             0,
                             prices,
                             fee,
                             n),

            stockBuySell(idx + 1,
                         1,
                         prices,
                         fee,
                         n));
    }

    return max(
        prices[idx] - fee +
            stockBuySell(idx + 1,
                         1,
                         prices,
                         fee,
                         n),

        stockBuySell(idx + 1,
                     0,
                     prices,
                     fee,
                     n));
}

int maxProfit(vector<int> &prices,
              int fee)
{
    return stockBuySell(
        0,
        1,
        prices,
        fee,
        prices.size());
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int stockBuySellOptimalMemoization(
    int idx,
    int buy,
    vector<int> &prices,
    int fee,
    int n,
    vector<vector<int>> &dp)
{
    if (idx == n)
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
                               fee,
                               n,
                               dp),

                       stockBuySellOptimalMemoization(
                           idx + 1,
                           1,
                           prices,
                           fee,
                           n,
                           dp));
    }

    return dp[idx][buy] =
               max(
                   prices[idx] - fee +
                       stockBuySellOptimalMemoization(
                           idx + 1,
                           1,
                           prices,
                           fee,
                           n,
                           dp),

                   stockBuySellOptimalMemoization(
                       idx + 1,
                       0,
                       prices,
                       fee,
                       n,
                       dp));
}

int maxProfitOptimalMemoization(
    vector<int> &prices,
    int fee)
{
    int n = prices.size();

    vector<vector<int>> dp(
        n,
        vector<int>(2, -1));

    return stockBuySellOptimalMemoization(
        0,
        1,
        prices,
        fee,
        n,
        dp);
}

// ---------------------------------------------------------------
// Tabulation
// ---------------------------------------------------------------

int maxProfitOptimalTabulation(
    vector<int> &prices,
    int fee)
{
    int n = prices.size();

    vector<vector<int>> dp(
        n + 1,
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
                prices[idx] - fee +
                    dp[idx + 1][1],

                dp[idx + 1][0]);
    }

    return dp[0][1];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Only the next day's state
// is required.
// ---------------------------------------------------------------

int maxProfitMostOptimized(
    vector<int> &prices,
    int fee)
{
    int n = prices.size();

    vector<int> dp(2, 0);
    vector<int> temp(2, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        // buy = 0
        temp[0] =
            max(
                prices[idx] +
                    dp[1] - fee,

                dp[0]);

        // buy = 1
        temp[1] =
            max(
                -prices[idx] +
                    dp[0],

                dp[1]);

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
            1, 3, 2, 8, 4, 9};

    int fee = 2;

    cout << "Maximum Profit (Recursion) : "
         << maxProfit(prices, fee);

    cout << "\nMaximum Profit (Memoization) : "
         << maxProfitOptimalMemoization(prices, fee);

    cout << "\nMaximum Profit (Tabulation) : "
         << maxProfitOptimalTabulation(prices, fee);

    cout << "\nMaximum Profit (Most Optimized) : "
         << maxProfitMostOptimized(prices, fee);

    return 0;
}