#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// We have infinite supply of every coin.
//
// We have to find the minimum number of coins
// required to make the given amount.
//
// Since every coin can be taken multiple times,
// after taking a coin we stay at the same index.
//
// State:
// dp[i][amt]
// = Minimum coins required to make amount 'amt'
// using coins from index 0 to i.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int coinChange(int amt, int n, vector<int> &c)
{

    if (n == 0)
    {
        if (amt % c[0] == 0)
            return amt / c[0];

        return 1e9;
    }

    if (amt == 0)
        return 0;

    int take = 1e9;

    if (amt >= c[n])
        take = 1 + coinChange(amt - c[n], n, c);

    int notTake = coinChange(amt, n - 1, c);

    return min(take, notTake);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int coinChangeOptimalMemoization(int amt,
                                 int n,
                                 vector<int> &c,
                                 vector<vector<int>> &dp)
{

    if (n == 0)
    {
        if (amt % c[0] == 0)
            return amt / c[0];

        return 1e9;
    }

    if (amt == 0)
        return 0;

    if (dp[n][amt] != -1)
        return dp[n][amt];

    int take = 1e9;

    if (amt >= c[n])
        take = 1 + coinChangeOptimalMemoization(amt - c[n],
                                                n,
                                                c,
                                                dp);

    int notTake = coinChangeOptimalMemoization(amt,
                                               n - 1,
                                               c,
                                               dp);

    return dp[n][amt] = min(take, notTake);
}

// ---------------------------------------------------------------
// Tabulation
//
// This time we'll build the answer from
// index 0 to n-1.
//
// Since we have infinite supply of every coin,
// while taking the current coin we stay
// in the same row.
// ---------------------------------------------------------------

int coinChangeOptimalTabulation(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

    // Base Case

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }

    int firstCoin = coins[0];

    for (int i = 0; i <= amount; i = i + firstCoin)
    {
        dp[0][i] = i / firstCoin;
    }

    // Build Answer

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            int notTake = dp[i - 1][j];

            int take = INT_MAX;

            if (j >= coins[i])
                take = dp[i][j - coins[i]] + 1;

            dp[i][j] = min(take, notTake);
        }
    }

    int ans = dp[n - 1][amount];

    if (ans >= 1e9)
        return -1;

    return ans;
}

// ---------------------------------------------------------------
// Space Optimization
//
// Since current row depends on
// previous row and current row,
// we'll keep one previous row
// and one current row.
// ---------------------------------------------------------------

int coinChangeMostOptimized(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<int> dp(amount + 1, 1e9);

    dp[0] = 0;

    int firstCoin = coins[0];

    for (int i = 0; i <= amount; i = i + firstCoin)
    {
        dp[i] = i / firstCoin;
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(amount + 1, 1e9);

        temp[0] = 0;

        for (int j = 1; j <= amount; j++)
        {
            int notTake = dp[j];

            int take = INT_MAX;

            if (j >= coins[i])
                take = temp[j - coins[i]] + 1;

            temp[j] = min(take, notTake);
        }

        dp = temp;
    }

    int ans = dp[amount];

    if (ans >= 1e9)
        return -1;

    return ans;
}

// ---------------------------------------------------------------
// Even More Optimization
//
// Since current row depends upon itself,
// we can completely remove the temp array
// and update the same array.
//
// This optimization is possible because
// it is an Unbounded Knapsack problem.
// ---------------------------------------------------------------

int coinChangeEvenMoreOptimized(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<int> dp(amount + 1, 1e9);

    dp[0] = 0;

    int firstCoin = coins[0];

    for (int i = 0; i <= amount; i = i + firstCoin)
    {
        dp[i] = i / firstCoin;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            int notTake = dp[j];

            int take = INT_MAX;

            if (j >= coins[i])
                take = dp[j - coins[i]] + 1;

            dp[j] = min(take, notTake);
        }
    }

    int ans = dp[amount];

    if (ans >= 1e9)
        return -1;

    return ans;
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int n = coins.size();

    cout << "Minimum Coins (Recursion) : ";

    int ans = coinChange(amount, n - 1, coins);

    if (ans >= 1e9)
        cout << -1;
    else
        cout << ans;

    vector<vector<int>> memo(n, vector<int>(amount + 1, -1));

    cout << "\nMinimum Coins (Memoization) : ";

    ans = coinChangeOptimalMemoization(amount,
                                       n - 1,
                                       coins,
                                       memo);

    if (ans >= 1e9)
        cout << -1;
    else
        cout << ans;

    cout << "\nMinimum Coins (Tabulation) : "
         << coinChangeOptimalTabulation(coins, amount);

    cout << "\nMinimum Coins (Most Optimized) : "
         << coinChangeMostOptimized(coins, amount);

    cout << "\nMinimum Coins (Even More Optimized) : "
         << coinChangeEvenMoreOptimized(coins, amount);

    return 0;
}