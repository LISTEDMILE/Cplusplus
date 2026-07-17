#include <iostream>
#include <vector>
#include <string>

using namespace std;

// DP Pattern:
//
// String DP
//
// Unlike Longest Common Subsequence,
// the characters must be continuous.
//
// If characters match,
// extend the previous substring.
//
// Otherwise,
// the current substring length becomes 0.
//
// State:
//
// dp[i][j]
//
// = Length of Longest Common Substring
// ending at
// text1[i-1] and text2[j-1].

// ---------------------------------------------------------------
// Tabulation
// ---------------------------------------------------------------

int LCSubStr(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1,
                           vector<int>(m + 1, 0));

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    string str1 = "ABCDGH";
    string str2 = "ACDGHR";

    cout << "Longest Common Substring Length : "
         << LCSubStr(str1, str2);

    return 0;
}