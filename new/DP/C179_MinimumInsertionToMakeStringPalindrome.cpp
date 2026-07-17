#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// We have to find the minimum number
// of insertions required to make
// a string palindrome.
//
// Observation:
//
// Longest Palindromic Subsequence
// = Longest Common Subsequence
// between the string and its reverse.
//
// Therefore,
//
// Minimum Insertions
// = Length of String - LPS

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int longestPalindromeSubsequence(int n1,
                                 int n2,
                                 string &s,
                                 string &sn)
{
    if (n1 < 0 || n2 < 0)
        return 0;

    if (s[n1] == sn[n2])
    {
        return 1 +
               longestPalindromeSubsequence(n1 - 1,
                                            n2 - 1,
                                            s,
                                            sn);
    }

    int reduceS =
        longestPalindromeSubsequence(n1 - 1,
                                     n2,
                                     s,
                                     sn);

    int reduceSn =
        longestPalindromeSubsequence(n1,
                                     n2 - 1,
                                     s,
                                     sn);

    return max(reduceS, reduceSn);
}

int minInsertions(string s)
{
    int n = s.size();

    string sn = s;

    reverse(sn.begin(), sn.end());

    int lps =
        longestPalindromeSubsequence(n - 1,
                                     n - 1,
                                     s,
                                     sn);

    return n - lps;
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int longestPalindromeSubsequenceOptimalMemoization(
    int n1,
    int n2,
    string &s,
    string &sn,
    vector<vector<int>> &dp)
{
    if (n1 < 0 || n2 < 0)
        return 0;

    if (dp[n1][n2] != -1)
        return dp[n1][n2];

    if (s[n1] == sn[n2])
    {
        return dp[n1][n2] =
                   1 +
                   longestPalindromeSubsequenceOptimalMemoization(
                       n1 - 1,
                       n2 - 1,
                       s,
                       sn,
                       dp);
    }

    int reduceS =
        longestPalindromeSubsequenceOptimalMemoization(
            n1 - 1,
            n2,
            s,
            sn,
            dp);

    int reduceSn =
        longestPalindromeSubsequenceOptimalMemoization(
            n1,
            n2 - 1,
            s,
            sn,
            dp);

    return dp[n1][n2] =
               max(reduceS, reduceSn);
}

int minInsertionsOptimalMemoization(string s)
{
    int n = s.size();

    string sn = s;

    reverse(sn.begin(), sn.end());

    vector<vector<int>> dp(n,
                           vector<int>(n, -1));

    int lps =
        longestPalindromeSubsequenceOptimalMemoization(
            n - 1,
            n - 1,
            s,
            sn,
            dp);

    return n - lps;
}

// ---------------------------------------------------------------
// Tabulation
//
// We reverse the string and find
// the Longest Common Subsequence.
//
// Answer = n - LPS
// ---------------------------------------------------------------

int minInsertionsOptimalTabulation(string s)
{
    int n = s.size();

    string sn = s;

    reverse(sn.begin(), sn.end());

    vector<vector<int>> dp(n + 1,
                           vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == sn[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                int reduceS = dp[i - 1][j];
                int reduceSn = dp[i][j - 1];

                dp[i][j] = max(reduceS, reduceSn);
            }
        }
    }

    return n - dp[n][n];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Only previous row is required.
// ---------------------------------------------------------------

int minInsertionsMostOptimized(string s)
{
    int n = s.size();

    string sn = s;

    reverse(sn.begin(), sn.end());

    vector<int> pre(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        vector<int> temp(n + 1, 0);

        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == sn[j - 1])
            {
                temp[j] = pre[j - 1] + 1;
            }
            else
            {
                temp[j] = max(pre[j], temp[j - 1]);
            }
        }

        pre = temp;
    }

    return n - pre[n];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    string s = "mbadm";

    cout << "Minimum Insertions (Recursion) : "
         << minInsertions(s);

    cout << "\nMinimum Insertions (Memoization) : "
         << minInsertionsOptimalMemoization(s);

    cout << "\nMinimum Insertions (Tabulation) : "
         << minInsertionsOptimalTabulation(s);

    cout << "\nMinimum Insertions (Most Optimized) : "
         << minInsertionsMostOptimized(s);

    return 0;
}