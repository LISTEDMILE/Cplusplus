#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// DP Pattern:
//
// String DP
//
// First find the Longest Common Subsequence.
//
// Then backtrack through the DP table.
//
// If characters match,
// include the character once.
//
// Otherwise,
// move towards the larger LCS value
// and include that character.
//
// Finally,
// reverse the constructed string.

// ---------------------------------------------------------------
// Tabulation
// ---------------------------------------------------------------

string shortestCommonSupersequence(string str1,
                                   string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1,
                           vector<int>(m + 1, 0));

    // Build LCS Table

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
            }
        }
    }

    // Backtracking

    int i = n;
    int j = m;

    string s = "";

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            s = s + str1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                s = s + str2[j - 1];
                j--;
            }
            else
            {
                s = s + str1[i - 1];
                i--;
            }
        }
    }

    while (i > 0)
    {
        s = s + str1[i - 1];
        i--;
    }

    while (j > 0)
    {
        s = s + str2[j - 1];
        j--;
    }

    reverse(s.begin(), s.end());

    return s;
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    string str1 = "abac";
    string str2 = "cab";

    cout << "Shortest Common Supersequence : "
         << shortestCommonSupersequence(str1, str2);

    return 0;
}