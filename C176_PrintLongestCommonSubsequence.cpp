#include <iostream>
#include <vector>
#include <string>

using namespace std;

// DP Pattern:
//
// String DP
//
// We first build the LCS DP table.
// Then we backtrack from dp[n][m]
// to reconstruct the actual LCS string.
//
// State:
//
// dp[i][j]
//
// = Length of Longest Common Subsequence
// considering first i characters of text1
// and first j characters of text2.

// ---------------------------------------------------------------
// Solution
// ---------------------------------------------------------------

string findLCS(int n1, int n2, string &text1, string &text2)
{

    vector<vector<int>> dp(n1 + 1,
                           vector<int>(n2 + 1, 0));

    // Base Case

    for (int i = 0; i <= n1; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= n2; j++)
        dp[0][j] = 0;

    // Build DP Table

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

    // Backtracking

    int i = n1;
    int j = n2;

    string s = "";

    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            s = text1[i - 1] + s;
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    return s;
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

    cout << "Longest Common Subsequence : "
         << findLCS(n1, n2, text1, text2);

    return 0;
}