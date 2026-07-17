#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// We have to divide the array into two subsets
// such that the difference of their sums is minimum.
//
// If one subset has sum = s1,
// then the other subset has sum = totalSum - s1.
//
// Difference = abs((totalSum-s1)-s1)
//
// We'll find all possible subset sums
// and choose the minimum difference.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

bool subsetSum(int idx, int target, vector<int> &nums)
{
    if (target == 0)
        return true;

    if (idx == 0)
        return nums[0] == target;

    bool notTake = subsetSum(idx - 1, target, nums);

    bool take = false;

    if (nums[idx] <= target)
    {
        take = subsetSum(idx - 1, target - nums[idx], nums);
    }

    return take || notTake;
}

int minimumDifference(vector<int> &nums)
{
    int n = nums.size();

    int sum = 0;

    for (int val : nums)
        sum += val;

    int minn = INT_MAX;

    for (int s1 = 0; s1 <= sum / 2; s1++)
    {
        if (subsetSum(n - 1, s1, nums))
        {
            minn = min(minn, abs((sum - s1) - s1));
        }
    }

    return minn;
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

bool subsetSumOptimalMemoization(int idx,
                                 int target,
                                 vector<int> &nums,
                                 vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (idx == 0)
        return nums[0] == target;

    if (dp[idx][target] != -1)
        return dp[idx][target];

    bool notTake = subsetSumOptimalMemoization(idx - 1,
                                               target,
                                               nums,
                                               dp);

    bool take = false;

    if (nums[idx] <= target)
    {
        take = subsetSumOptimalMemoization(idx - 1,
                                           target - nums[idx],
                                           nums,
                                           dp);
    }

    return dp[idx][target] = take || notTake;
}

int minimumDifferenceOptimalMemoization(vector<int> &nums)
{
    int n = nums.size();

    int sum = 0;

    for (int val : nums)
        sum += val;

    vector<vector<int>> dp(n,
                           vector<int>(sum + 1, -1));

    int minn = INT_MAX;

    for (int s1 = 0; s1 <= sum / 2; s1++)
    {
        if (subsetSumOptimalMemoization(n - 1, s1, nums, dp))
        {
            minn = min(minn, abs((sum - s1) - s1));
        }
    }

    return minn;
}

// ---------------------------------------------------------------
// Tabulation
//
// Find all possible subset sums.
// ---------------------------------------------------------------

int minimumDifferenceOptimalTabulation(vector<int> &nums)
{
    int n = nums.size();

    int sum = 0;

    for (int val : nums)
        sum += val;

    vector<vector<bool>> dp(n,
                            vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool notTake = dp[i - 1][j];

            bool take = false;

            if (nums[i] <= j)
            {
                take = dp[i - 1][j - nums[i]];
            }

            dp[i][j] = take || notTake;
        }
    }

    int minn = INT_MAX;

    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n - 1][i])
        {
            minn = min(minn, abs((sum - i) - i));
        }
    }

    return minn;
}

// ---------------------------------------------------------------
// Space Optimization
//
// Only previous row is required.
// ---------------------------------------------------------------

int minimumDifferenceMostOptimized(vector<int> &nums)
{
    int n = nums.size();

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    vector<bool> prev(sum + 1, false);

    prev[0] = true;

    prev[nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> temp(sum + 1, false);

        temp[0] = true;

        for (int j = 1; j <= sum; j++)
        {
            bool notTake = prev[j];

            bool take = false;

            if (nums[i] <= j)
            {
                take = prev[j - nums[i]];
            }

            temp[j] = take || notTake;
        }

        prev = temp;
    }

    int minn = INT_MAX;

    for (int i = 0; i <= sum / 2; i++)
    {
        if (prev[i])
        {
            minn = min(minn, abs((sum - i) - i));
        }
    }

    return minn;
}

int main()
{
    vector<int> nums = {1, 6, 11, 5};

    cout << "Minimum Difference (Recursion) : "
         << minimumDifference(nums);

    cout << "\nMinimum Difference (Memoization) : "
         << minimumDifferenceOptimalMemoization(nums);

    cout << "\nMinimum Difference (Tabulation) : "
         << minimumDifferenceOptimalTabulation(nums);

    cout << "\nMinimum Difference (Most Optimized) : "
         << minimumDifferenceMostOptimized(nums);

    return 0;
}