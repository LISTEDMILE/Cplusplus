#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Longest Subarray With Sum K
// ===============================================================
//
// Find the length of the longest subarray whose sum is equal to k.
//
// We have 3 approaches:
//
// 1. Brute Force
// 2. Sliding Window      -> works when there are NO negative numbers
// 3. Prefix Sum + Map    -> works with negative numbers too
//
// ===============================================================

// ---------------------------------------------------------------
// 1. Brute Force
// ---------------------------------------------------------------
//
// Try every possible subarray and calculate its sum.
//
// Time Complexity : O(n²)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int longestSubarrayBruteForce(vector<int> &nums, long long k)
{
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        long long sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += nums[j];

            if (sum == k)
                ans = max(ans, j - i + 1);
        }
    }

    return ans;
}

// ---------------------------------------------------------------
// 2. Sliding Window
// ---------------------------------------------------------------
//
// This works when the array contains NO negative numbers.
//
// Since all numbers are non-negative:
//
// sum > k -> move i forward
// sum < k -> move j forward
// sum == k -> update answer
//
// Time Complexity : O(n)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int n = a.size();
    int i = 0;
    int j = 0;
    long long sum = 0;
    int ans = 0;

    while (j < n)
    {

        sum += a[j++];

        while (i <= j && sum > k)
            sum -= a[i++];

        if (sum == k)
            ans = max(ans, j - i);
    }

    return ans;
}

// ---------------------------------------------------------------
// 3. Prefix Sum + Map
// ---------------------------------------------------------------
//
// This approach works even when the array contains NEGATIVE
// numbers.
//
// At index i:
//
// current sum = sum
//
// We need an earlier prefix sum:
//
// sum - previousSum = k
//
// Therefore:
//
// previousSum = sum-k
//
// Store the FIRST occurrence of every prefix sum because we want
// the longest possible subarray.
//
// Time Complexity : O(n log n) using map
// Space Complexity : O(n)
// ---------------------------------------------------------------

int getLongestSubarray(vector<int> &nums, int k)
{
    map<int, int> m;

    int ans = 0;

    int sum = 0;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        if (sum == k)
            ans = i + 1;
        else
        {
            int temp = sum - k;

            if (m.find(temp) != m.end())
            {
                ans = max(ans, i - m[temp]);
            }
        }

        if (m.find(sum) == m.end())
            m[sum] = i;
    }

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    // -----------------------------------------------------------
    // Test 1
    // No negative numbers
    // Sliding Window can be used.
    // -----------------------------------------------------------

    vector<int> nums1 =
        {
            1, 2, 3, 1, 1, 1, 1};

    long long k1 = 3;

    cout << "Brute Force : "
         << longestSubarrayBruteForce(nums1, k1)
         << endl;

    cout << "Sliding Window : "
         << longestSubarrayWithSumK(nums1, k1)
         << endl;

    // -----------------------------------------------------------
    // Test 2
    // Negative numbers present
    // Sliding Window cannot be used.
    // Prefix Sum + Map is used.
    // -----------------------------------------------------------

    vector<int> nums2 =
        {
            1, -1, 5, -2, 3};

    int k2 = 3;

    cout << "\nBrute Force : "
         << longestSubarrayBruteForce(nums2, k2)
         << endl;

    cout << "Prefix Sum + Map : "
         << getLongestSubarray(nums2, k2)
         << endl;

    return 0;
}