#include <iostream>
#include <vector>
#include <string>

using namespace std;

// DP Pattern:
//
// String DP
//
// State:
//
// dp[i][j]
//
// = Length of Longest Common Subsequence
// considering first i characters of text1
// and first j characters of text2.

// ---------------------------------------------------------------
// Recursion (Negative Index)
// ---------------------------------------------------------------

int longestCommonSubsequence(int n1,
                             int n2,
                             string &t1,
                             string &t2)
{

    if (n1 < 0 || n2 < 0)
        return 0;

    if (t1[n1] == t2[n2])
        return 1 + longestCommonSubsequence(n1 - 1,
                                            n2 - 1,
                                            t1,
                                            t2);

    int reduceT1 =
        longestCommonSubsequence(n1 - 1,
                                 n2,
                                 t1,
                                 t2);

    int reduceT2 =
        longestCommonSubsequence(n1,
                                 n2 - 1,
                                 t1,
                                 t2);

    return max(reduceT1, reduceT2);
}

// ---------------------------------------------------------------
// Shifted Index Recursion
//
// Instead of using negative indices,
// we'll shift every index by one.
//
// Base Case:
//
// if(i<=0 || j<=0)
// ---------------------------------------------------------------

int longestCommonSubsequenceShifted(int n1,
                                    int n2,
                                    string &t1,
                                    string &t2)
{

    if (n1 <= 0 || n2 <= 0)
        return 0;

    if (t1[n1 - 1] == t2[n2 - 1])
        return 1 +
               longestCommonSubsequenceShifted(n1 - 1,
                                               n2 - 1,
                                               t1,
                                               t2);

    int reduceT1 =
        longestCommonSubsequenceShifted(n1 - 1,
                                        n2,
                                        t1,
                                        t2);

    int reduceT2 =
        longestCommonSubsequenceShifted(n1,
                                        n2 - 1,
                                        t1,
                                        t2);

    return max(reduceT1, reduceT2);
}

// ---------------------------------------------------------------
// Memoization (Shifted Index)
// ---------------------------------------------------------------

int longestCommonSubsequenceOptimalMemoization(int n1,
                                               int n2,
                                               string &t1,
                                               string &t2,
                                               vector<vector<int>> &dp)
{

    if (n1 <= 0 || n2 <= 0)
        return 0;

    if (dp[n1][n2] != -1)
        return dp[n1][n2];

    if (t1[n1 - 1] == t2[n2 - 1])
        return dp[n1][n2] =
                   1 +
                   longestCommonSubsequenceOptimalMemoization(
                       n1 - 1,
                       n2 - 1,
                       t1,
                       t2,
                       dp);

    int reduceT1 =
        longestCommonSubsequenceOptimalMemoization(
            n1 - 1,
            n2,
            t1,
            t2,
            dp);

    int reduceT2 =
        longestCommonSubsequenceOptimalMemoization(
            n1,
            n2 - 1,
            t1,
            t2,
            dp);

    return dp[n1][n2] =
               max(reduceT1, reduceT2);
}

// ---------------------------------------------------------------
// Tabulation
//
// We'll build the answer from
// index 1 to n.
//
// Since we are using shifted indexing,
// row 0 and column 0 represent
// empty strings.
// ---------------------------------------------------------------

int longestCommonSubsequenceOptimalTabulation(string text1,
                                              string text2)
{
    int n1 = text1.size();
    int n2 = text2.size();

    vector<vector<int>> dp(n1 + 1,
                           vector<int>(n2 + 1, 0));

    // Base Case

    for (int i = 0; i <= n1; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= n2; j++)
        dp[0][j] = 0;

    // Build Answer

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                int reduceT1 = dp[i - 1][j];
                int reduceT2 = dp[i][j - 1];

                dp[i][j] = max(reduceT1, reduceT2);
            }
        }
    }

    return dp[n1][n2];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Since current row depends only on
// previous row and current row,
// we'll use two arrays.
// ---------------------------------------------------------------

int longestCommonSubsequenceMostOptimized(string text1,
                                          string text2)
{
    int n1 = text1.size();
    int n2 = text2.size();

    vector<int> dp(n2 + 1, 0);

    for (int i = 1; i <= n1; i++)
    {
        vector<int> temp(n2 + 1, 0);

        for (int j = 1; j <= n2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                temp[j] = dp[j - 1] + 1;
            }
            else
            {
                int reduceT1 = dp[j];
                int reduceT2 = temp[j - 1];

                temp[j] = max(reduceT1, reduceT2);
            }
        }

        dp = temp;
    }

    return dp[n2];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    int n1 = text1.size();
    int n2 = text2.size();

    cout << "LCS Length (Recursion) : "
         << longestCommonSubsequence(n1 - 1,
                                     n2 - 1,
                                     text1,
                                     text2);

    cout << "\nLCS Length (Shifted Recursion) : "
         << longestCommonSubsequenceShifted(n1,
                                            n2,
                                            text1,
                                            text2);

    vector<vector<int>> memo(n1 + 1,
                             vector<int>(n2 + 1, -1));

    cout << "\nLCS Length (Memoization) : "
         << longestCommonSubsequenceOptimalMemoization(n1,
                                                       n2,
                                                       text1,
                                                       text2,
                                                       memo);

    cout << "\nLCS Length (Tabulation) : "
         << longestCommonSubsequenceOptimalTabulation(text1,
                                                      text2);

    cout << "\nLCS Length (Most Optimized) : "
         << longestCommonSubsequenceMostOptimized(text1,
                                                  text2);

    return 0;
}