#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// We have to assign '+' and '-' signs
// to every element.
//
// Finally the expression should become
// equal to the given target.
//
// We can convert it into
// Count Subset Sum problem.
//
// Let
//
// S1 - S2 = target
// S1 + S2 = totalSum
//
// Therefore
//
// S1 = (target + totalSum)/2
//
// Now the problem becomes:
//
// Count the number of subsets
// having sum = S1.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int helper(vector<int> &nums, int idx, int tar)
{

    if (idx == 0)
    {
        if (tar == 0 && nums[0] == 0)
            return 2;

        if (tar == 0 || tar == nums[0])
            return 1;

        return 0;
    }

    int notTake = helper(nums, idx - 1, tar);

    int take = 0;

    if (nums[idx] <= tar)
        take = helper(nums, idx - 1, tar - nums[idx]);

    return take + notTake;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (abs(target) > sum)
        return 0;

    if ((target + sum) % 2 != 0)
        return 0;

    int tar = (target + sum) / 2;

    return helper(nums, n - 1, tar);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int helperOptimalMemoization(vector<int> &nums,
                             int idx,
                             int tar,
                             vector<vector<int>> &dp)
{

    if (idx == 0)
    {
        if (tar == 0 && nums[0] == 0)
            return 2;

        if (tar == 0 || tar == nums[0])
            return 1;

        return 0;
    }

    if (dp[idx][tar] != -1)
        return dp[idx][tar];

    int notTake = helperOptimalMemoization(nums,
                                           idx - 1,
                                           tar,
                                           dp);

    int take = 0;

    if (nums[idx] <= tar)
        take = helperOptimalMemoization(nums,
                                        idx - 1,
                                        tar - nums[idx],
                                        dp);

    return dp[idx][tar] = take + notTake;
}

int findTargetSumWaysOptimalMemoization(vector<int> &nums,
                                        int target)
{

    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (abs(target) > sum)
        return 0;

    if ((target + sum) % 2 != 0)
        return 0;

    int tar = (target + sum) / 2;

    vector<vector<int>> dp(n,
                           vector<int>(tar + 1, -1));

    return helperOptimalMemoization(nums,
                                    n - 1,
                                    tar,
                                    dp);
}

// ---------------------------------------------------------------
// Tabulation
//
// We'll build the answer from
// index 0 to n-1.
//
// dp[i][j]
// = Number of subsets having sum j.
// ---------------------------------------------------------------

int findTargetSumWaysOptimalTabulation(vector<int> &nums,
                                       int target)
{

    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (abs(target) > sum)
        return 0;

    if ((target + sum) % 2 != 0)
        return 0;

    int tar = (target + sum) / 2;

    vector<vector<int>> dp(n,
                           vector<int>(tar + 1, 0));

    if (nums[0] == 0)
        dp[0][0] = 2;
    else
    {
        dp[0][0] = 1;

        if (nums[0] <= tar)
            dp[0][nums[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            int notTake = dp[i - 1][j];

            int take = 0;

            if (j >= nums[i])
                take = dp[i - 1][j - nums[i]];

            dp[i][j] = take + notTake;
        }
    }

    return dp[n - 1][tar];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Since current row depends only
// on previous row,
// we'll use two arrays.
// ---------------------------------------------------------------

int findTargetSumWaysMostOptimized(vector<int> &nums,
                                   int target)
{

    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (abs(target) > sum)
        return 0;

    if ((target + sum) % 2 != 0)
        return 0;

    int tar = (target + sum) / 2;

    vector<int> prev(tar + 1, 0);

    if (nums[0] == 0)
        prev[0] = 2;
    else
    {
        prev[0] = 1;

        if (nums[0] <= tar)
            prev[nums[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(tar + 1, 0);

        for (int j = 0; j <= tar; j++)
        {
            int notTake = prev[j];

            int take = 0;

            if (j >= nums[i])
                take = prev[j - nums[i]];

            temp[j] = take + notTake;
        }

        prev = temp;
    }

    return prev[tar];
}

// ---------------------------------------------------------------
// Even More Optimization
//
// Since current row depends upon
// the previous values only,
// we can completely remove temp
// by traversing from right to left.
//
// This is your final optimized solution.
// ---------------------------------------------------------------

int findTargetSumWaysEvenMoreOptimized(vector<int> &nums,
                                       int target)
{

    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (abs(target) > sum)
        return 0;

    if ((target + sum) % 2 != 0)
        return 0;

    int tar = (target + sum) / 2;

    vector<int> dp(tar + 1, 0);

    if (nums[0] == 0)
        dp[0] = 2;
    else
    {
        dp[0] = 1;

        if (nums[0] <= tar)
            dp[nums[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = tar; j >= 0; j--)
        {
            int notTake = dp[j];

            int take = 0;

            if (j >= nums[i])
                take = dp[j - nums[i]];

            dp[j] = take + notTake;
        }
    }

    return dp[tar];
}

// ---------------------------------------------------------------
// main()
// ---------------------------------------------------------------

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << "Target Sum Ways (Recursion) : "
         << findTargetSumWays(nums, target);

    cout << "\nTarget Sum Ways (Memoization) : "
         << findTargetSumWaysOptimalMemoization(nums, target);

    cout << "\nTarget Sum Ways (Tabulation) : "
         << findTargetSumWaysOptimalTabulation(nums, target);

    cout << "\nTarget Sum Ways (Most Optimized) : "
         << findTargetSumWaysMostOptimized(nums, target);

    cout << "\nTarget Sum Ways (Even More Optimized) : "
         << findTargetSumWaysEvenMoreOptimized(nums, target);

    return 0;
}