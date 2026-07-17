#include <iostream>
#include <vector>

using namespace std;

// We can buy and sell the stock
// any number of times.
//
// At every day we have two choices.
//
// buy = 1
// We are allowed to buy.
//
// buy = 0
// We already own a stock
// and are allowed to sell.
//
// At every state,
// either perform the action
// or skip the current day.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int stockBuySell(int idx,
                 bool buy,
                 vector<int> &prices,
                 int n)
{
    if (idx == n)
        return 0;

    int notTake =
        stockBuySell(idx + 1,
                     buy,
                     prices,
                     n);

    int take;

    if (buy)
    {
        take =
            -prices[idx] +
            stockBuySell(idx + 1,
                         false,
                         prices,
                         n);
    }
    else
    {
        take =
            prices[idx] +
            stockBuySell(idx + 1,
                         true,
                         prices,
                         n);
    }

    return max(take, notTake);
}

int maxProfit(vector<int> &prices)
{
    return stockBuySell(0,
                        true,
                        prices,
                        prices.size());
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int stockBuySellOptimalMemoization(
    int idx,
    bool buy,
    vector<int> &prices,
    int n,
    vector<vector<int>> &dp)
{
    if (idx == n)
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    int notTake =
        stockBuySellOptimalMemoization(
            idx + 1,
            buy,
            prices,
            n,
            dp);

    int take;

    if (buy)
    {
        take =
            -prices[idx] +
            stockBuySellOptimalMemoization(
                idx + 1,
                false,
                prices,
                n,
                dp);
    }
    else
    {
        take =
            prices[idx] +
            stockBuySellOptimalMemoization(
                idx + 1,
                true,
                prices,
                n,
                dp);
    }

    return dp[idx][buy] =
               max(take, notTake);
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
        true,
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
        n + 1,
        vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;

            if (buy)
            {
                profit =
                    max(-prices[idx] +
                            dp[idx + 1][0],
                        dp[idx + 1][1]);
            }
            else
            {
                profit =
                    max(prices[idx] +
                            dp[idx + 1][1],
                        dp[idx + 1][0]);
            }

            dp[idx][buy] = profit;
        }
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
    vector<int> &prices)
{
    int n = prices.size();

    vector<int> ahead(2, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<int> curr(2, 0);

        // buy = 1

        curr[1] =
            max(-prices[idx] +
                    ahead[0],
                ahead[1]);

        // buy = 0

        curr[0] =
            max(prices[idx] +
                    ahead[1],
                ahead[0]);

        ahead = curr;
    }

    return ahead[1];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

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