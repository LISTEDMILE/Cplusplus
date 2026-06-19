#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// We have a rod of length N.
//
// price[i] denotes the price of
// rod having length (i+1).
//
// We can cut the rod into
// multiple pieces.
//
// Since every piece can be used
// multiple times,
// after taking a piece
// we'll stay at the same index.
//
// State:
//
// dp[i][len]
//
// = Maximum profit using
// rod lengths from index 0 to i
// to make total rod length len.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int cutRod(int n,
           int N,
           vector<int> &price)
{

    if (n == 0)
    {
        return N * price[0];
    }

    int notTake = cutRod(n - 1,
                         N,
                         price);

    int take = INT_MIN;

    if (N >= n + 1)
        take = cutRod(n,
                      N - (n + 1),
                      price) +
               price[n];

    return max(notTake, take);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int cutRodOptimalMemoization(int n,
                             int N,
                             vector<int> &price,
                             vector<vector<int>> &dp)
{

    if (n == 0)
    {
        return N * price[0];
    }

    if (dp[n][N] != -1)
        return dp[n][N];

    int notTake =
        cutRodOptimalMemoization(n - 1,
                                 N,
                                 price,
                                 dp);

    int take = INT_MIN;

    if (N >= n + 1)
        take =
            cutRodOptimalMemoization(n,
                                     N - (n + 1),
                                     price,
                                     dp) +
            price[n];

    return dp[n][N] = max(notTake, take);
}

// ---------------------------------------------------------------
// Tabulation
//
// We'll build the answer from
// index 0 to n-1.
//
// Since every rod length can be used
// multiple times,
// while taking a rod piece
// we'll stay in the same row.
// ---------------------------------------------------------------

int cutRodOptimalTabulation(vector<int> &price,
                            int n)
{
    int TLenght = n;

    vector<vector<int>> dp(n,
                           vector<int>(TLenght + 1, 0));

    // Base Case

    for (int j = 0; j <= TLenght; j++)
    {
        dp[0][j] = j * price[0];
    }

    // Build Answer

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= TLenght; j++)
        {
            int notTake = dp[i - 1][j];

            int take = INT_MIN;

            if (j >= i + 1)
                take = price[i] + dp[i][j - (i + 1)];

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n - 1][TLenght];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Since current row depends on
// previous row and current row,
// we'll use two arrays.
// ---------------------------------------------------------------

int cutRodMostOptimized(vector<int> &price,
                        int n)
{
    int TLenght = n;

    vector<int> dp(TLenght + 1, 0);

    // Base Case

    for (int j = 0; j <= TLenght; j++)
    {
        dp[j] = j * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(TLenght + 1, 0);

        for (int j = 0; j <= TLenght; j++)
        {
            int notTake = dp[j];

            int take = INT_MIN;

            if (j >= i + 1)
                take = price[i] + temp[j - (i + 1)];

            temp[j] = max(take, notTake);
        }

        dp = temp;
    }

    return dp[TLenght];
}

// ---------------------------------------------------------------
// Even More Optimization
//
// Since current row depends upon
// itself, we can completely remove
// the temp array.
//
// This optimization is possible because
// Rod Cutting is an Unbounded Knapsack
// problem.
// ---------------------------------------------------------------

int cutRodEvenMoreOptimized(vector<int> &price,
                            int n)
{
    int TLenght = n;

    vector<int> dp(TLenght + 1, 0);

    // Base Case

    for (int j = 0; j <= TLenght; j++)
    {
        dp[j] = j * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= TLenght; j++)
        {
            int notTake = dp[j];

            int take = INT_MIN;

            if (j >= i + 1)
                take = price[i] + dp[j - (i + 1)];

            dp[j] = max(take, notTake);
        }
    }

    return dp[TLenght];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    vector<int> price = {2, 5, 7, 8, 10};

    int n = price.size();

    cout << "Maximum Profit (Recursion) : "
         << cutRod(n - 1,
                   n,
                   price);

    vector<vector<int>> memo(n,
                             vector<int>(n + 1, -1));

    cout << "\nMaximum Profit (Memoization) : "
         << cutRodOptimalMemoization(n - 1,
                                     n,
                                     price,
                                     memo);

    cout << "\nMaximum Profit (Tabulation) : "
         << cutRodOptimalTabulation(price,
                                    n);

    cout << "\nMaximum Profit (Most Optimized) : "
         << cutRodMostOptimized(price,
                                n);

    cout << "\nMaximum Profit (Even More Optimized) : "
         << cutRodEvenMoreOptimized(price,
                                    n);

    return 0;
}