#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// DP Pattern:
//
// String DP
//
// Longest Palindromic Subsequence
// can be converted into
// Longest Common Subsequence.
//
// text1 = Original String
// text2 = Reverse of Original String
//
// Answer = LCS(text1, text2).

// ---------------------------------------------------------------
// Tabulation (Space Optimized)
// ---------------------------------------------------------------

int longestPalindromeSubseq(string s)
{
    int n = s.size();

    string sn = s;

    reverse(sn.begin(), sn.end());

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        vector<int> temp(n + 1, 0);

        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == sn[j - 1])
            {
                temp[j] = dp[j - 1] + 1;
            }
            else
            {
                temp[j] = max(dp[j], temp[j - 1]);
            }
        }

        dp = temp;
    }

    return dp[n];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    string s = "bbbab";

    cout << "Longest Palindromic Subsequence Length : "
         << longestPalindromeSubseq(s);

    return 0;
}