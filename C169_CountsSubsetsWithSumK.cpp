#include <iostream>
#include <vector>

using namespace std;

// Count the number of subsets having sum = K.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int countSubsets(int idx, int target, vector<int> &nums)
{
    // Base Cases

    // Not Take

    // Take

    // Return total ways
}

int countSubsetsRecursion(vector<int> &nums, int k)
{
    int n = nums.size();

    return countSubsets(n - 1, k, nums);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int countSubsetsMemo(int idx,
                     int target,
                     vector<int> &nums,
                     vector<vector<int>> &dp)
{
    // Base Cases

    // DP Check

    // Not Take

    // Take

    // Store and Return
}

int countSubsetsMemoization(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<vector<int>> dp(n,
                           vector<int>(k + 1, -1));

    return countSubsetsMemo(n - 1,
                            k,
                            nums,
                            dp);
}

// ---------------------------------------------------------------
// Tabulation
// ---------------------------------------------------------------

int countSubsetsTabulation(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<vector<int>> dp(n,
                           vector<int>(k + 1, 0));

    // Base Initialization

    // Fill DP Table

    // Return Answer
}

// ---------------------------------------------------------------
// Space Optimization
// ---------------------------------------------------------------

int countSubsetsOptimized(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<int> prev(k + 1, 0);

    // Base Initialization

    // DP Transition

    // Return Answer
}

// ---------------------------------------------------------------

int main()
{
    vector<int> nums = {1, 2, 2, 3};

    int k = 3;

    cout << "Count (Recursion) : "
         << countSubsetsRecursion(nums, k);

    cout << "\nCount (Memoization) : "
         << countSubsetsMemoization(nums, k);

    cout << "\nCount (Tabulation) : "
         << countSubsetsTabulation(nums, k);

    cout << "\nCount (Most Optimized) : "
         << countSubsetsOptimized(nums, k);

    return 0;
}