#include <iostream>
#include <vector>

using namespace std;

// We have infinite supply of every coin.
//
// We have to find the total number of ways
// to make the given amount.
//
// Since we can use a coin multiple times,
// after taking a coin we'll stay
// at the same index.
//
// State:
// dp[i][amt]
// = Number of ways to make amount 'amt'
// using coins from index 0 to i.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int change(int amt, vector<int> &coins, int n)
{

    if (amt == 0)
        return 1;

    if (n == 0)
        return (amt % coins[0] == 0);

    int notTake = change(amt, coins, n - 1);

    int take = 0;

    if (amt >= coins[n])
        take = change(amt - coins[n], coins, n);

    return take + notTake;
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int changeOptimalMemoization(int amt,
                             vector<int> &coins,
                             int n,
                             vector<vector<int>> &dp)
{

    if (amt == 0)
        return 1;

    if (n == 0)
        return (amt % coins[0] == 0);

    if (dp[n][amt] != -1)
        return dp[n][amt];

    int notTake = changeOptimalMemoization(amt,
                                           coins,
                                           n - 1,
                                           dp);

    int take = 0;

    if (amt >= coins[n])
        take = changeOptimalMemoization(amt - coins[n],
                                        coins,
                                        n,
                                        dp);

    return dp[n][amt] = take + notTake;
}

// ---------------------------------------------------------------
// Tabulation
//
// We'll build the answer from
// index 0 to n-1.
//
// Since we have infinite supply of every coin,
// while taking a coin we stay
// in the same row.
// ---------------------------------------------------------------

int changeOptimalTabulation(int amount,
                            vector<int> &coins)
{
    int n = coins.size();

    vector<vector<int>> dp(n,
                           vector<int>(amount + 1, 0));

    // Base Case

    if (coins[0] == 0)
        dp[0][0] = 2;
    else if (coins[0] <= amount)
    {
        int firstCoin = coins[0];

        for (int i = 0; i <= amount; i = i + firstCoin)
        {
            dp[0][i] = 1;
        }
    }

    // Build Answer

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int notTake = dp[i - 1][j];

            int take = 0;

            if (coins[i] <= j)
                take = dp[i][j - coins[i]];

            dp[i][j] = take + notTake;
        }
    }

    return dp[n - 1][amount];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Current row depends upon
// previous row and current row.
// ---------------------------------------------------------------

int changeMostOptimized(int amount,
                        vector<int> &coins)
{
    int n = coins.size();

    vector<int> dp(amount + 1, 0);

    if (coins[0] == 0)
        dp[0] = 2;
    else if (coins[0] <= amount)
    {
        int firstCoin = coins[0];

        for (int i = 0; i <= amount; i = i + firstCoin)
        {
            dp[i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(amount + 1, 0);

        temp[0] = 1;

        for (int j = 0; j <= amount; j++)
        {
            int notTake = dp[j];

            int take = 0;

            if (coins[i] <= j)
                take = temp[j - coins[i]];

            temp[j] = take + notTake;
        }

        dp = temp;
    }

    return dp[amount];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    int n = coins.size();

    cout << "Number of Ways (Recursion) : "
         << change(amount, coins, n - 1);

    vector<vector<int>> memo(n,
                             vector<int>(amount + 1, -1));

    cout << "\nNumber of Ways (Memoization) : "
         << changeOptimalMemoization(amount,
                                     coins,
                                     n - 1,
                                     memo);

    cout << "\nNumber of Ways (Tabulation) : "
         << changeOptimalTabulation(amount, coins);

    cout << "\nNumber of Ways (Most Optimized) : "
         << changeMostOptimized(amount, coins);

    return 0;
}