#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Rotate Array
// ===============================================================
//
// Given an array, rotate it to the right by k positions.
//
// Example:
//
// nums = {1,2,3,4,5,6,7}
// k = 3
//
// Answer:
//
// {5,6,7,1,2,3,4}
//
// We have 3 common approaches:
//
// 1. Using an extra array
// 2. Repeatedly shifting
// 3. Reversal Algorithm
//
// ===============================================================

// ---------------------------------------------------------------
// Solution 1
// Using Extra Array
// ---------------------------------------------------------------
//
// Put every element directly at its new position.
//
// New position:
//
// (i + k) % n
//
// Time Complexity : O(n)
// Space Complexity : O(n)
// ---------------------------------------------------------------

void rotateUsingExtraArray(vector<int> &nums, int k)
{
    int n = nums.size();

    k = k % n;

    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = nums[i];
    }

    nums = temp;
}

// ---------------------------------------------------------------
// Solution 2
// Repeatedly Shift One Position
// ---------------------------------------------------------------
//
// Rotate the array one position at a time.
//
// Time Complexity : O(n × k)
// Space Complexity : O(1)
// ---------------------------------------------------------------

void rotateUsingShifting(vector<int> &nums, int k)
{
    int n = nums.size();

    k = k % n;

    for (int i = 0; i < k; i++)
    {
        int last = nums[n - 1];

        for (int j = n - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }

        nums[0] = last;
    }
}

// ---------------------------------------------------------------
// Solution 3
// Reversal Algorithm
// ---------------------------------------------------------------
//
// Example:
//
// {1,2,3,4,5,6,7}
//
// k = 3
//
// Reverse last k:
//
// {1,2,3,4,7,6,5}
//
// Reverse first n-k:
//
// {4,3,2,1,7,6,5}
//
// Reverse everything:
//
// {5,6,7,1,2,3,4}
//
// Time Complexity : O(n)
// Space Complexity : O(1)
// ---------------------------------------------------------------

void rotateUsingReversal(vector<int> &nums, int k)
{
    k = k % nums.size();

    reverse(nums.end() - k, nums.end());

    reverse(nums.begin(), nums.end() - k);

    reverse(nums.begin(), nums.end());
}

// ===============================================================
// Print Array
// ===============================================================

void printArray(vector<int> &nums)
{
    for (int it : nums)
    {
        cout << it << " ";
    }

    cout << endl;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<int> nums1 =
        {
            1, 2, 3, 4, 5, 6, 7};

    vector<int> nums2 =
        {
            1, 2, 3, 4, 5, 6, 7};

    vector<int> nums3 =
        {
            1, 2, 3, 4, 5, 6, 7};

    int k = 3;

    // -----------------------------------------------------------
    // Solution 1
    // -----------------------------------------------------------

    rotateUsingExtraArray(nums1, k);

    cout << "Using Extra Array : ";

    printArray(nums1);

    // -----------------------------------------------------------
    // Solution 2
    // -----------------------------------------------------------

    rotateUsingShifting(nums2, k);

    cout << "Using Shifting : ";

    printArray(nums2);

    // -----------------------------------------------------------
    // Solution 3
    // -----------------------------------------------------------

    rotateUsingReversal(nums3, k);

    cout << "Using Reversal : ";

    printArray(nums3);

    return 0;
}