#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Missing Number
// ===============================================================
//
// Given an array containing n distinct numbers taken from
// the range [0, n], find the missing number.
//
// Example:
//
// nums = {3,0,1}
//
// n = 3
//
// Range = {0,1,2,3}
//
// Missing Number = 2
//
// ===============================================================

// ---------------------------------------------------------------
// Brute Force
// ---------------------------------------------------------------
//
// For every number from 0 to n,
// search whether it exists in the array.
//
// Time Complexity : O(n²)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int missingNumberBruteForce(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i <= n; i++)
    {
        bool found = false;

        for (int j = 0; j < n; j++)
        {
            if (nums[j] == i)
            {
                found = true;
                break;
            }
        }

        if (!found)
            return i;
    }

    return -1;
}

// ---------------------------------------------------------------
// Better
// Using Hashing
// ---------------------------------------------------------------
//
// Store every number in a hash array.
//
// Then check which number from 0 to n
// is not present.
//
// Time Complexity : O(n)
// Space Complexity : O(n)
// ---------------------------------------------------------------

int missingNumberBetter(vector<int> &nums)
{
    int n = nums.size();

    vector<int> hash(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        hash[nums[i]] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        if (hash[i] == 0)
            return i;
    }

    return -1;
}

// ---------------------------------------------------------------
// Optimal
// Using Sum Formula
// ---------------------------------------------------------------
//
// Sum of numbers from 0 to n:
//
// n * (n + 1) / 2
//
// Missing Number:
//
// desiredSum - actualSum
//
// long long is used to avoid integer overflow.
//
// Time Complexity : O(n)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int missingNumberOptimal(vector<int> &nums)
{
    long long sum =
        accumulate(nums.begin(),
                   nums.end(),
                   0LL);

    long long desiredSum =
        (long long)nums.size() *
        (nums.size() + 1) / 2;

    return desiredSum - sum;
}

// ---------------------------------------------------------------
// Even More Optimal
// Using XOR
// ---------------------------------------------------------------
//
// XOR properties:
//
// x ^ x = 0
//
// x ^ 0 = x
//
// Therefore, if we XOR all numbers from
// 0 to n and all numbers present in nums,
// every existing number cancels out.
//
// The remaining number is the missing number.
//
// Time Complexity : O(n)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int missingNumberMostOptimized(vector<int> &nums)
{
    int n = nums.size();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];

        ans ^= i;
    }

    ans ^= n;

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<int> nums =
        {
            3, 0, 1};

    cout << "Missing Number (Brute Force) : "
         << missingNumberBruteForce(nums)
         << endl;

    cout << "Missing Number (Better) : "
         << missingNumberBetter(nums)
         << endl;

    cout << "Missing Number (Optimal) : "
         << missingNumberOptimal(nums)
         << endl;

    cout << "Missing Number (Most Optimized) : "
         << missingNumberMostOptimized(nums)
         << endl;

    return 0;
}