#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Max Consecutive Ones
// ===============================================================
//
// Given a binary array, find the maximum number of consecutive
// 1s in the array.
//
// Example:
//
// nums = {1,1,0,1,1,1}
//
// Answer = 3
//
// Approach:
//
// count -> stores the current consecutive number of 1s.
//
// ans -> stores the maximum consecutive 1s found so far.
//
// If current element is 1:
//      increase count.
//
// If current element is 0:
//      reset count to 0.
//
// Time Complexity : O(n)
// Space Complexity : O(1)
// ===============================================================

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int ans = 0;

    int count = 0;

    for (int val : nums)
    {
        if (val == 1)
        {
            count++;

            ans = max(ans, count);
        }
        else
        {
            count = 0;
        }
    }

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<int> nums =
        {
            1, 1, 0, 1, 1, 1};

    cout << "Maximum Consecutive Ones : "
         << findMaxConsecutiveOnes(nums)
         << endl;

    return 0;
}