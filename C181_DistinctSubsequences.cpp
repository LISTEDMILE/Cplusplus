#include <iostream>
#include <vector>
#include <string>

using namespace std;

// We have to count the number of distinct
// subsequences of string s
// which are equal to string t.
//
// At every character of s,
// we have two choices:
//
// 1. Ignore the current character.
// 2. Take the current character
//    if it matches the current
//    character of t.
//
// Sum of both choices gives
// the total number of distinct
// subsequences.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int distinctSubsequences(int i,
                         int j,
                         string &s,
                         string &t)
{
    if (j < 0)
        return 1;

    if (i < 0)
        return 0;

    int notTake =
        distinctSubsequences(i - 1,
                             j,
                             s,
                             t);

    int take = 0;

    if (s[i] == t[j])
    {
        take =
            distinctSubsequences(i - 1,
                                 j - 1,
                                 s,
                                 t);
    }

    return take + notTake;
}

int numDistinct(string s,
                string t)
{
    int n = s.size();
    int m = t.size();

    return distinctSubsequences(n - 1,
                                m - 1,
                                s,
                                t);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int distinctSubsequencesOptimalMemoization(
    int i,
    int j,
    string &s,
    string &t,
    vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;

    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int notTake =
        distinctSubsequencesOptimalMemoization(
            i - 1,
            j,
            s,
            t,
            dp);

    int take = 0;

    if (s[i] == t[j])
    {
        take =
            distinctSubsequencesOptimalMemoization(
                i - 1,
                j - 1,
                s,
                t,
                dp);
    }

    return dp[i][j] =
               take + notTake;
}

int numDistinctOptimalMemoization(string s,
                                  string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n,
                           vector<int>(m, -1));

    return distinctSubsequencesOptimalMemoization(
        n - 1,
        m - 1,
        s,
        t,
        dp);
}

// ---------------------------------------------------------------
// Memoization (Shifted Index)
// ---------------------------------------------------------------

int distinctSubsequencesShiftedOptimalMemoization(
    int i,
    int j,
    string &s,
    string &t,
    vector<vector<int>> &dp)
{
    if (j == 0)
        return 1;

    if (i == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int notTake =
        distinctSubsequencesShiftedOptimalMemoization(
            i - 1,
            j,
            s,
            t,
            dp);

    int take = 0;

    if (s[i - 1] == t[j - 1])
    {
        take =
            distinctSubsequencesShiftedOptimalMemoization(
                i - 1,
                j - 1,
                s,
                t,
                dp);
    }

    return dp[i][j] =
               take + notTake;
}

int numDistinctShiftedOptimalMemoization(
    string s,
    string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, -1));

    return distinctSubsequencesShiftedOptimalMemoization(
        n,
        m,
        s,
        t,
        dp);
}

// ---------------------------------------------------------------
// Tabulation
//
// dp[i][j]
//
// = Number of ways to form
// first j characters of t
// using first i characters of s.
// ---------------------------------------------------------------

int numDistinctOptimalTabulation(
    string s,
    string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int notTake = dp[i - 1][j];

            int take = 0;

            if (s[i - 1] == t[j - 1])
            {
                take = dp[i - 1][j - 1];
            }

            dp[i][j] = take + notTake;
        }
    }

    return dp[n][m];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Only previous row is required.
// ---------------------------------------------------------------

int numDistinctMostOptimized(string s,
                             string t)
{
    int n = s.size();
    int m = t.size();

    vector<int> dp(m + 1, 0);

    // Base Case

    dp[0] = 1;

    for (int i = 1; i <= m; i++)
    {
        dp[i] = 0;
    }

    // Build Answer

    for (int i = 1; i <= n; i++)
    {
        vector<int> temp(m + 1, 0);

        temp[0] = 1;

        for (int j = 1; j <= m; j++)
        {
            int notTake = dp[j];

            int take = 0;

            if (s[i - 1] == t[j - 1])
            {
                take = dp[j - 1];
            }

            temp[j] = take + notTake;
        }

        dp = temp;
    }

    return dp[m];
}

// ---------------------------------------------------------------
// Even More Optimization
//
// Since current row depends only on
// the previous row,
// we can completely remove the
// temporary array by traversing
// from right to left.
// ---------------------------------------------------------------

int numDistinctEvenMoreOptimized(string s,
                                 string t)
{
    int n = s.size();
    int m = t.size();

    vector<double> dp(m + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= m; i++)
        dp[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            double notTake = dp[j];

            double take = 0;

            if (s[i - 1] == t[j - 1])
            {
                take = dp[j - 1];
            }

            dp[j] = take + notTake;
        }
    }

    return (int)dp[m];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    string s = "babgbag";
    string t = "bag";

    // see tle aaega iske bad bhi most optimized me bhi usse bachne ke liye data type alter karenge jaise even more optimized wale me kiya h....
    cout << "Distinct Subsequences (Recursion) : "
         << numDistinct(s, t);

    cout << "\nDistinct Subsequences (Memoization) : "
         << numDistinctOptimalMemoization(s, t);

    cout << "\nDistinct Subsequences (Shifted Memoization) : "
         << numDistinctShiftedOptimalMemoization(s, t);

    cout << "\nDistinct Subsequences (Tabulation) : "
         << numDistinctOptimalTabulation(s, t);

    cout << "\nDistinct Subsequences (Most Optimized) : "
         << numDistinctMostOptimized(s, t);

    cout << "\nDistinct Subsequences (Most Optimized Even More) : "
         << numDistinctEvenMoreOptimized(s, t);

    return 0;
}