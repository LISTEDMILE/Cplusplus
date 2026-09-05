#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Maximum Subarray Sum
// ===============================================================
//
// Find the maximum sum of any contiguous subarray.
//
// Example:
// arr = {-2,1,-3,4,-1,2,1,-5,4}
//
// Answer = 6
// Subarray = {4,-1,2,1}
//
// ===============================================================

// ---------------------------------------------------------------
// 1. Brute Force
// ---------------------------------------------------------------
//
// Generate every possible subarray and calculate its sum.
//
// Time Complexity : O(n²)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int findMaxSumBruteForce(vector<int> &arr, int n)
{
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            ans = max(ans, sum);
        }
    }

    return ans;
}

// ---------------------------------------------------------------
// 2. Better
// ---------------------------------------------------------------
//
// Instead of calculating the sum again for every subarray,
// maintain the sum while extending the subarray.
//
// Time Complexity : O(n²)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int findMaxSumBetter(vector<int> &arr, int n)
{
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            ans = max(ans, sum);
        }
    }

    return ans;
}

// ---------------------------------------------------------------
// 3. Optimal
// Kadane's Algorithm
// ---------------------------------------------------------------
//
// cnt -> current subarray sum
// ans -> maximum sum found so far
//
// If cnt becomes negative, discard the current subarray because
// carrying a negative sum can only decrease the sum of a future
// subarray.
//
// Time Complexity : O(n)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int findMaxSumOptimal(vector<int> &arr, int n)
{
    int ans = INT_MIN;

    int cnt = 0;

    for (int val : arr)
    {
        cnt += val;

        ans = max(ans, cnt);

        if (cnt < 0)
            cnt = 0;
    }

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Maximum Subarray Sum (Brute Force) : "
         << findMaxSumBruteForce(arr, n)
         << endl;

    cout << "Maximum Subarray Sum (Better) : "
         << findMaxSumBetter(arr, n)
         << endl;

    cout << "Maximum Subarray Sum (Kadane) : "
         << findMaxSumOptimal(arr, n)
         << endl;

    return 0;
}