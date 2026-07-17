#include <iostream>
#include <vector>
#include <string>

using namespace std;

// We have to find the minimum number
// of operations required to convert
// string s1 into string s2.
//
// Allowed Operations:
//
// 1. Insert
// 2. Delete
// 3. Replace
//
// At every mismatch,
// we'll try all three operations
// and take the minimum answer.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int editDistance(int n,
                 int m,
                 string &s1,
                 string &s2)
{
    if (n < 0)
        return m + 1;

    if (m < 0)
        return n + 1;

    if (s1[n] == s2[m])
    {
        return editDistance(n - 1,
                            m - 1,
                            s1,
                            s2);
    }

    int insert =
        1 +
        editDistance(n,
                     m - 1,
                     s1,
                     s2);

    int deletee =
        1 +
        editDistance(n - 1,
                     m,
                     s1,
                     s2);

    int replace =
        1 +
        editDistance(n - 1,
                     m - 1,
                     s1,
                     s2);

    return min(insert,
               min(deletee, replace));
}

int minDistance(string s1,
                string s2)
{
    int n = s1.size();
    int m = s2.size();

    return editDistance(n - 1,
                        m - 1,
                        s1,
                        s2);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int editDistanceOptimalMemoization(
    int n,
    int m,
    string &s1,
    string &s2,
    vector<vector<int>> &dp)
{
    if (n < 0)
        return m + 1;

    if (m < 0)
        return n + 1;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n] == s2[m])
    {
        return dp[n][m] =
                   editDistanceOptimalMemoization(
                       n - 1,
                       m - 1,
                       s1,
                       s2,
                       dp);
    }

    int insert =
        1 +
        editDistanceOptimalMemoization(
            n,
            m - 1,
            s1,
            s2,
            dp);

    int deletee =
        1 +
        editDistanceOptimalMemoization(
            n - 1,
            m,
            s1,
            s2,
            dp);

    int replace =
        1 +
        editDistanceOptimalMemoization(
            n - 1,
            m - 1,
            s1,
            s2,
            dp);

    return dp[n][m] =
               min(insert,
                   min(deletee, replace));
}

int minDistanceOptimalMemoization(
    string s1,
    string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(
        n,
        vector<int>(m, -1));

    return editDistanceOptimalMemoization(
        n - 1,
        m - 1,
        s1,
        s2,
        dp);
}

// ---------------------------------------------------------------
// Memoization (Shifted Index)
// ---------------------------------------------------------------

int editDistanceShiftedOptimalMemoization(
    int n,
    int m,
    string &s1,
    string &s2,
    vector<vector<int>> &dp)
{
    if (n <= 0)
        return m;

    if (m <= 0)
        return n;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] =
                   editDistanceShiftedOptimalMemoization(
                       n - 1,
                       m - 1,
                       s1,
                       s2,
                       dp);
    }

    int insert =
        1 +
        editDistanceShiftedOptimalMemoization(
            n,
            m - 1,
            s1,
            s2,
            dp);

    int deletee =
        1 +
        editDistanceShiftedOptimalMemoization(
            n - 1,
            m,
            s1,
            s2,
            dp);

    int replace =
        1 +
        editDistanceShiftedOptimalMemoization(
            n - 1,
            m - 1,
            s1,
            s2,
            dp);

    return dp[n][m] =
               min(insert,
                   min(deletee, replace));
}

int minDistanceShiftedOptimalMemoization(
    string s1,
    string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, -1));

    return editDistanceShiftedOptimalMemoization(
        n,
        m,
        s1,
        s2,
        dp);
}

// ---------------------------------------------------------------
// Tabulation
//
// Build the answer from
// smaller strings to larger strings.
// ---------------------------------------------------------------

int minDistanceOptimalTabulation(
    string s1,
    string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int insert = 1 + dp[i][j - 1];

                int deletee = 1 + dp[i - 1][j];

                int replace = 1 + dp[i - 1][j - 1];

                dp[i][j] =
                    min(insert,
                        min(deletee, replace));
            }
        }
    }

    return dp[n][m];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Only previous row is required.
// ---------------------------------------------------------------

int minDistanceMostOptimized(string s1,
                             string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<int> dp(m + 1, 0);
    vector<int> temp(m + 1, 0);

    // Base Case

    for (int j = 0; j <= m; j++)
    {
        dp[j] = j;
    }

    // Build Answer

    for (int i = 1; i <= n; i++)
    {
        temp[0] = i;

        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                temp[j] = dp[j - 1];
            }
            else
            {
                int insert = 1 + temp[j - 1];

                int deletee = 1 + dp[j];

                int replace = 1 + dp[j - 1];

                temp[j] =
                    min(insert,
                        min(deletee, replace));
            }
        }

        dp = temp;
    }

    return dp[m];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    string s1 = "horse";
    string s2 = "ros";

    cout << "Minimum Operations (Recursion) : "
         << minDistance(s1, s2);

    cout << "\nMinimum Operations (Memoization) : "
         << minDistanceOptimalMemoization(s1, s2);

    cout << "\nMinimum Operations (Shifted Memoization) : "
         << minDistanceShiftedOptimalMemoization(s1, s2);

    cout << "\nMinimum Operations (Tabulation) : "
         << minDistanceOptimalTabulation(s1, s2);

    cout << "\nMinimum Operations (Most Optimized) : "
         << minDistanceMostOptimized(s1, s2);

    return 0;
}