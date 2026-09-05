#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Majority Element
// ===============================================================
//
// Find the element that appears more than n/2 times.
//
// 3 Approaches:
//
// 1. Brute Force
// 2. Hashing
// 3. Moore's Voting Algorithm
//
// ===============================================================

// ---------------------------------------------------------------
// 1. Brute Force
// ---------------------------------------------------------------
//
// For every element, count how many times it appears.
//
// Time Complexity : O(n²)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int majorityElementBruteForce(vector<int> &nums)
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

        if (count > n / 2)
            return nums[i];
    }

    return -1;
}

// ---------------------------------------------------------------
// 2. Better
// Using Hashing
// ---------------------------------------------------------------
//
// Store the frequency of every element.
//
// Time Complexity : O(n) average
// Space Complexity : O(n)
// ---------------------------------------------------------------

int majorityElementBetter(vector<int> &nums)
{
    unordered_map<int, int> m;

    int n = nums.size();

    for (int val : nums)
    {
        m[val]++;

        if (m[val] > n / 2)
            return val;
    }

    return -1;
}

// ---------------------------------------------------------------
// 3. Optimal
// Moore's Voting Algorithm
// ---------------------------------------------------------------
//
// Maintain:
//
// el -> current candidate
// c  -> current count
//
// Same element  -> c++
// Different     -> c--
//
// When c becomes 0, choose the current element as the
// new candidate.
//
// Since a majority element is guaranteed to exist,
// the final candidate is the majority element.
//
// Time Complexity : O(n)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int majorityElementOptimal(vector<int> &nums)
{
    int c = 1;

    int el = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == el)
            c++;

        else
        {
            if (c == 0)
            {
                el = nums[i];

                c = 1;
            }
            else
                c--;
        }
    }

    return el;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<int> nums =
        {
            2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element (Brute Force) : "
         << majorityElementBruteForce(nums)
         << endl;

    cout << "Majority Element (Hashing) : "
         << majorityElementBetter(nums)
         << endl;

    cout << "Majority Element (Moore's Voting) : "
         << majorityElementOptimal(nums)
         << endl;

    return 0;
}