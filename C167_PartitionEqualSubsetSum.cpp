#include <iostream>
#include <vector>

using namespace std;

// We have to divide the array into two subsets
// such that both subsets have equal sum.
//
// If total sum is odd,
// then partition is not possible.
//
// Otherwise,
// target = totalSum / 2.
//
// Now the problem becomes:
//
// Can we find a subset whose sum is equal to target?

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

bool canPartition(int idx, int halfSum, vector<int> &nums)
{
    if (idx == 0)
        return nums[0] == halfSum;

    if (halfSum == 0)
        return true;

    bool notTake = canPartition(idx - 1, halfSum, nums);

    bool take = false;

    if (halfSum >= nums[idx])
    {
        take = canPartition(idx - 1, halfSum - nums[idx], nums);
    }

    return take || notTake;
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

bool canPartitionOptimalMemoization(int idx,
                                    int halfSum,
                                    vector<int> &nums,
                                    vector<vector<int>> &dp)
{
    if (idx == 0)
        return nums[0] == halfSum;

    if (halfSum == 0)
        return true;

    if (dp[idx][halfSum] != -1)
        return dp[idx][halfSum];

    bool notTake = canPartitionOptimalMemoization(idx - 1,
                                                  halfSum,
                                                  nums,
                                                  dp);

    bool take = false;

    if (halfSum >= nums[idx])
    {
        take = canPartitionOptimalMemoization(idx - 1,
                                              halfSum - nums[idx],
                                              nums,
                                              dp);
    }

    return dp[idx][halfSum] = (take || notTake);
}

// ---------------------------------------------------------------
// Tabulation
//
// Build the answer from index 0 to n-1.
// ---------------------------------------------------------------

bool canPartitionOptimalTabulation(vector<int> &nums)
{
    int n = nums.size();

    int sum = 0;

    for (int val : nums)
        sum += val;

    if (sum % 2 != 0)
        return false;

    int tar = sum / 2;

    vector<vector<bool>> dp(n,
                            vector<bool>(tar + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (nums[0] <= tar)
        dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= tar; j++)
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

    return dp[n - 1][tar];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Only previous row is required.
// ---------------------------------------------------------------

bool canPartitionMostOptimized(vector<int> &nums)
{
    int n = nums.size();

    int sum = 0;

    for (int val : nums)
        sum += val;

    if (sum % 2 != 0)
        return false;

    int tar = sum / 2;

    vector<bool> prev(tar + 1, false);

    prev[0] = true;

    if (nums[0] <= tar)
        prev[nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> temp(tar + 1, false);

        temp[0] = true;

        for (int j = 1; j <= tar; j++)
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

    return prev[tar];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};

    int n = nums.size();

    int sum = 0;

    for (int val : nums)
        sum += val;

    if (sum % 2 != 0)
    {
        cout << "Partition Possible (Recursion) : false";
        cout << "\nPartition Possible (Memoization) : false";
        cout << "\nPartition Possible (Tabulation) : false";
        cout << "\nPartition Possible (Most Optimized) : false";

        return 0;
    }

    int tar = sum / 2;

    cout << "Partition Possible (Recursion) : "
         << canPartition(n - 1, tar, nums);

    vector<vector<int>> dp(n,
                           vector<int>(tar + 1, -1));

    cout << "\nPartition Possible (Memoization) : "
         << canPartitionOptimalMemoization(n - 1,
                                           tar,
                                           nums,
                                           dp);

    cout << "\nPartition Possible (Tabulation) : "
         << canPartitionOptimalTabulation(nums);

    cout << "\nPartition Possible (Most Optimized) : "
         << canPartitionMostOptimized(nums);

    return 0;
}