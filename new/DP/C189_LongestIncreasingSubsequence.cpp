#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// We have to find the length
// of the Longest Increasing
// Subsequence.
//
// State:
//
// idx
// Current index.
//
// prev
// Index of the previously
// selected element.
//
// prev = -1
// means no element has
// been selected yet.
//
// At every index,
// either take the element
// or skip it.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int longestIncreasingSubsequence(
    vector<int> &arr,
    int n,
    int idx,
    int prev)
{
    if (idx == n)
        return 0;

    int notTake =
        longestIncreasingSubsequence(
            arr,
            n,
            idx + 1,
            prev);

    int take = INT_MIN;

    if (prev == -1 ||
        arr[idx] > arr[prev])
    {
        take =
            1 +
            longestIncreasingSubsequence(
                arr,
                n,
                idx + 1,
                idx);
    }

    return max(take, notTake);
}

int lengthOfLIS(vector<int> &nums)
{
    return longestIncreasingSubsequence(
        nums,
        nums.size(),
        0,
        -1);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int longestIncreasingSubsequenceOptimalMemoization(
    vector<int> &arr,
    int n,
    int idx,
    int prev,
    vector<vector<int>> &dp)
{
    if (idx == n)
        return 0;

    if (dp[idx][prev + 1] != -1)
        return dp[idx][prev + 1];

    int notTake =
        longestIncreasingSubsequenceOptimalMemoization(
            arr,
            n,
            idx + 1,
            prev,
            dp);

    int take = INT_MIN;

    if (prev == -1 ||
        arr[idx] > arr[prev])
    {
        take =
            1 +
            longestIncreasingSubsequenceOptimalMemoization(
                arr,
                n,
                idx + 1,
                idx,
                dp);
    }

    return dp[idx][prev + 1] =
               max(take, notTake);
}

int lengthOfLISOptimalMemoization(
    vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(
        n,
        vector<int>(n + 1, -1));

    return longestIncreasingSubsequenceOptimalMemoization(
        nums,
        n,
        0,
        -1,
        dp);
}

// ---------------------------------------------------------------
// Tabulation
// ---------------------------------------------------------------

int lengthOfLISOptimalTabulation(
    vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(n + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev = idx - 1;
             prev >= -1;
             prev--)
        {
            int notTake =
                dp[idx + 1][prev + 1];

            int take = INT_MIN;

            if (prev == -1 ||
                nums[idx] > nums[prev])
            {
                take =
                    1 +
                    dp[idx + 1][idx + 1];
            }

            dp[idx][prev + 1] =
                max(take, notTake);
        }
    }

    return dp[0][0];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Only the next row is required.
// ---------------------------------------------------------------

int lengthOfLISMostOptimized(
    vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<int> temp(n + 1, 0);

        for (int prev = idx - 1;
             prev >= -1;
             prev--)
        {
            int notTake =
                dp[prev + 1];

            int take = INT_MIN;

            if (prev == -1 ||
                nums[idx] > nums[prev])
            {
                take =
                    1 +
                    dp[idx + 1];
            }

            temp[prev + 1] =
                max(take, notTake);
        }

        dp = temp;
    }

    return dp[0];
}

// ---------------------------------------------------------------
// Even Better Optimization
//
// Instead of storing
// (idx, prev),
// let dp[i] denote the length
// of the Longest Increasing
// Subsequence ending at i.
//
// Transition:
//
// dp[i] = 1 + max(dp[j])
// where
// j < i
// and
// nums[j] < nums[i]
//
// Time  : O(n²)
// Space : O(n)
// ---------------------------------------------------------------

int lengthOfLISEvenBetter(
    vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        int maxLength = 0;

        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                maxLength =
                    max(maxLength,
                        dp[j]);
            }
        }

        dp[i] = maxLength + 1;

        ans = max(ans,
                  dp[i]);
    }

    return ans;
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    vector<int> nums =
        {
            10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Length of LIS (Recursion) : "
         << lengthOfLIS(nums);

    cout << "\nLength of LIS (Memoization) : "
         << lengthOfLISOptimalMemoization(nums);

    cout << "\nLength of LIS (Tabulation) : "
         << lengthOfLISOptimalTabulation(nums);

    cout << "\nLength of LIS (Most Optimized) : "
         << lengthOfLISMostOptimized(nums);

    cout << "\nLength of LIS (Even Better) : "
         << lengthOfLISEvenBetter(nums);

    return 0;
}