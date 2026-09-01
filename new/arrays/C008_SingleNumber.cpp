#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Single Number
// ===============================================================
//
// Every element appears twice except one element.
// Find the element that appears only once.
//
// Example:
//
// nums = {4,1,2,1,2}
//
// Answer = 4
//
// ===============================================================

// ---------------------------------------------------------------
// Brute Force
// ---------------------------------------------------------------
//
// For every element, count how many times it appears.
//
// If frequency == 1, that is our answer.
//
// Time Complexity : O(n²)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int singleNumberBruteForce(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])

                count++;
        }

        if (count == 1)

            return nums[i];
    }

    return -1;
}

// ---------------------------------------------------------------
// Better
// Using Hashing
// ---------------------------------------------------------------
//
// Store the frequency of every number.
//
// Then find the number whose frequency is 1.
//
// Time Complexity : O(n)
// Space Complexity : O(n)
// ---------------------------------------------------------------

int singleNumberBetter(vector<int> &nums)
{
    unordered_map<int, int> m;

    for (int val : nums)

        m[val]++;

    for (auto it : m)
    {
        if (it.second == 1)

            return it.first;
    }

    return -1;
}

// ---------------------------------------------------------------
// Optimal
// Using XOR
// ---------------------------------------------------------------
//
// XOR properties:
//
// x ^ x = 0
//
// x ^ 0 = x
//
// Therefore, all duplicate numbers cancel each other.
//
// The number remaining is the single number.
//
// Time Complexity : O(n)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int singleNumberOptimal(vector<int> &nums)
{
    int ans = 0;

    for (int val : nums)

        ans = ans ^ val;

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<int> nums =
        {
            4, 1, 2, 1, 2};

    cout << "Single Number (Brute Force) : "
         << singleNumberBruteForce(nums)
         << endl;

    cout << "Single Number (Better) : "
         << singleNumberBetter(nums)
         << endl;

    cout << "Single Number (Optimal) : "
         << singleNumberOptimal(nums)
         << endl;

    return 0;
}