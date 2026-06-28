#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//------------------------------------------------------------
// 1. Recursion
//------------------------------------------------------------
bool validStringRecursion(string &s, int idx, int count) {

    if (count < 0)
        return false;

    if (idx == s.size())
        return count == 0;

    if (s[idx] == '(')
        return validStringRecursion(s, idx + 1, count + 1);

    if (s[idx] == ')')
        return validStringRecursion(s, idx + 1, count - 1);

    // '*'
    return validStringRecursion(s, idx + 1, count + 1) ||
           validStringRecursion(s, idx + 1, count - 1) ||
           validStringRecursion(s, idx + 1, count);
}

//------------------------------------------------------------
// 2. Memoization
//------------------------------------------------------------
bool validStringMemo(string &s, int idx, int count,
                     vector<vector<int>> &dp) {

    if (count < 0)
        return false;

    if (idx == s.size())
        return count == 0;

    if (dp[idx][count] != -1)
        return dp[idx][count];

    bool ans;

    if (s[idx] == '(')
        ans = validStringMemo(s, idx + 1, count + 1, dp);

    else if (s[idx] == ')')
        ans = validStringMemo(s, idx + 1, count - 1, dp);

    else
        ans = validStringMemo(s, idx + 1, count + 1, dp) ||
              validStringMemo(s, idx + 1, count - 1, dp) ||
              validStringMemo(s, idx + 1, count, dp);

    return dp[idx][count] = ans;
}

//------------------------------------------------------------
// 3. Greedy (Optimal)
//------------------------------------------------------------
bool validStringGreedy(string &s) {

    int low = 0;
    int high = 0;

    for (char ch : s) {

        if (ch == '(') {
            low++;
            high++;
        }
        else if (ch == ')') {
            low--;
            high--;
        }
        else { // '*'
            low--;
            high++;
        }

        if (high < 0)
            return false;

        low = max(low, 0);
    }

    return low == 0;
}

//------------------------------------------------------------
// Main
//------------------------------------------------------------
int main() {

    string s = "((*)(**(()*)";

    cout << "\nRecursion : ";
    if (validStringRecursion(s, 0, 0))
        cout << "True";
    else
        cout << "False";

    vector<vector<int>> dp(s.size() + 1,
                           vector<int>(s.size() + 1, -1));

    cout << "\nMemoization : ";
    if (validStringMemo(s, 0, 0, dp))
        cout << "True";
    else
        cout << "False";

    cout << "\nGreedy : ";
    if (validStringGreedy(s))
        cout << "True";
    else
        cout << "False";

    return 0;
}