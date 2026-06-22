#include <iostream>
#include <vector>
#include <string>

using namespace std;

// We have to check whether the pattern
// matches the string.
//
// Pattern contains:
// ?  -> Matches any one character.
// *  -> Matches any sequence of characters.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

bool wildcardMatching(int n,
                      int m,
                      string &s,
                      string &p)
{
    if (n < 0 && m < 0)
        return true;

    if (m < 0)
        return false;

    if (n < 0)
    {
        for (int i = m; i >= 0; i--)
        {
            if (p[i] != '*')
                return false;
        }
        return true;
    }

    if (s[n] == p[m] || p[m] == '?')
    {
        return wildcardMatching(n - 1,
                                m - 1,
                                s,
                                p);
    }

    if (p[m] == '*')
    {
        return wildcardMatching(n - 1,
                                m,
                                s,
                                p) ||
               wildcardMatching(n,
                                m - 1,
                                s,
                                p);
    }

    return false;
}

bool isMatch(string s,
             string p)
{
    return wildcardMatching(s.size() - 1,
                            p.size() - 1,
                            s,
                            p);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

bool wildcardMatchingOptimalMemoization(
    int n,
    int m,
    string &s,
    string &p,
    vector<vector<int>> &dp)
{
    if (n < 0 && m < 0)
        return true;

    if (m < 0)
        return false;

    if (n < 0)
    {
        for (int i = m; i >= 0; i--)
        {
            if (p[i] != '*')
                return false;
        }
        return true;
    }

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s[n] == p[m] || p[m] == '?')
    {
        return dp[n][m] =
                   wildcardMatchingOptimalMemoization(
                       n - 1,
                       m - 1,
                       s,
                       p,
                       dp);
    }

    if (p[m] == '*')
    {
        return dp[n][m] =
                   wildcardMatchingOptimalMemoization(
                       n - 1,
                       m,
                       s,
                       p,
                       dp) ||
                   wildcardMatchingOptimalMemoization(
                       n,
                       m - 1,
                       s,
                       p,
                       dp);
    }

    return dp[n][m] = false;
}

bool isMatchOptimalMemoization(
    string s,
    string p)
{
    int n = s.size();
    int m = p.size();

    vector<vector<int>> dp(
        n,
        vector<int>(m, -1));

    return wildcardMatchingOptimalMemoization(
        n - 1,
        m - 1,
        s,
        p,
        dp);
}

// ---------------------------------------------------------------
// Memoization (Shifted Index)
// ---------------------------------------------------------------

bool wildcardMatchingShiftedOptimalMemoization(
    int n,
    int m,
    string &s,
    string &p,
    vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
        return true;

    if (m == 0)
        return false;

    if (n == 0)
    {
        for (int i = m; i >= 1; i--)
        {
            if (p[i - 1] != '*')
                return false;
        }
        return true;
    }

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s[n - 1] == p[m - 1] ||
        p[m - 1] == '?')
    {
        return dp[n][m] =
                   wildcardMatchingShiftedOptimalMemoization(
                       n - 1,
                       m - 1,
                       s,
                       p,
                       dp);
    }

    if (p[m - 1] == '*')
    {
        return dp[n][m] =
                   wildcardMatchingShiftedOptimalMemoization(
                       n - 1,
                       m,
                       s,
                       p,
                       dp) ||
                   wildcardMatchingShiftedOptimalMemoization(
                       n,
                       m - 1,
                       s,
                       p,
                       dp);
    }

    return dp[n][m] = false;
}

bool isMatchShiftedOptimalMemoization(
    string s,
    string p)
{
    int n = s.size();
    int m = p.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, -1));

    return wildcardMatchingShiftedOptimalMemoization(
        n,
        m,
        s,
        p,
        dp);
}

// ---------------------------------------------------------------
// Tabulation
// ---------------------------------------------------------------

bool isMatchOptimalTabulation(
    string s,
    string p)
{
    int n = s.size();
    int m = p.size();

    vector<vector<bool>> dp(
        n + 1,
        vector<bool>(m + 1, false));

    dp[0][0] = true;

    for (int j = 1; j <= m; j++)
    {
        bool flag = true;

        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }

        dp[0][j] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = false;

        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] ||
                p[j - 1] == '?')
            {
                dp[i][j] =
                    dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] =
                    dp[i - 1][j] ||
                    dp[i][j - 1];
            }
        }
    }

    return dp[n][m];
}

// ---------------------------------------------------------------
// Space Optimization
// ---------------------------------------------------------------

bool isMatchMostOptimized(string s,
                          string p)
{
    int n = s.size();
    int m = p.size();

    vector<bool> dp(m + 1, false);

    dp[0] = true;

    // First Row

    for (int j = 1; j <= m; j++)
    {
        bool flag = true;

        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }

        dp[j] = flag;
    }

    // Build Answer

    for (int i = 1; i <= n; i++)
    {
        vector<bool> temp(m + 1, false);

        temp[0] = false;

        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] ||
                p[j - 1] == '?')
            {
                temp[j] = dp[j - 1];
            }
            else if (p[j - 1] == '*')
            {
                temp[j] = dp[j] || temp[j - 1];
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
    string s = "adceb";
    string p = "*a*b";

    cout << "Wildcard Matching (Recursion) : "
         << isMatch(s, p);

    cout << "\nWildcard Matching (Memoization) : "
         << isMatchOptimalMemoization(s, p);

    cout << "\nWildcard Matching (Shifted Memoization) : "
         << isMatchShiftedOptimalMemoization(s, p);

    cout << "\nWildcard Matching (Tabulation) : "
         << isMatchOptimalTabulation(s, p);

    cout << "\nWildcard Matching (Most Optimized) : "
         << isMatchMostOptimized(s, p);

    return 0;
}