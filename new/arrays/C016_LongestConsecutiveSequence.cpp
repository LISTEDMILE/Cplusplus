#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Longest Consecutive Sequence
// ===============================================================
//
// Find the length of the longest sequence of consecutive numbers.
//
// Example:
//
// arr = {100, 4, 200, 1, 3, 2}
//
// Answer = 4
//
// Sequence = {1, 2, 3, 4}
//
// ===============================================================

// ---------------------------------------------------------------
// 1. Brute Force
// ---------------------------------------------------------------
//
// For every element, repeatedly search for the next consecutive
// element in the array.
//
// Time Complexity : O(n²)
// Space Complexity : O(1)
// ---------------------------------------------------------------

int lengthOfLongestConsecutiveSequenceBruteForce(vector<int> &arr, int n)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int cnt = 1;

        while (true)
        {
            bool found = false;

            for (int j = 0; j < n; j++)
            {
                if (arr[j] == current + 1)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                break;

            current++;
            cnt++;
        }

        ans = max(ans, cnt);
    }

    return ans;
}

// ---------------------------------------------------------------
// 2. Better
// ---------------------------------------------------------------
//
// Sort the array first.
//
// After sorting, consecutive elements can be found by simply
// checking neighbouring elements.
//
// Time Complexity : O(n log n)
// Space Complexity : O(1) excluding sorting space
// ---------------------------------------------------------------

int lengthOfLongestConsecutiveSequenceBetter(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());

    int cnt = 1;
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
            cnt++;

        else if (arr[i] != arr[i - 1])
            cnt = 1;

        ans = max(ans, cnt);
    }

    return ans;
}

// ---------------------------------------------------------------
// 3. Optimal
// ---------------------------------------------------------------
//
// Use an unordered_set.
//
// For every number, only start counting if there is no number
// immediately before it.
//
// Example:
//
// {1,2,3,4}
//
// 1 has no 0 -> start sequence
// 2 has 1 -> don't start
// 3 has 2 -> don't start
// 4 has 3 -> don't start
//
// This ensures every consecutive sequence is traversed only once.
//
// Time Complexity : O(n) average
// Space Complexity : O(n)
// ---------------------------------------------------------------

int lengthOfLongestConsecutiveSequenceOptimal(vector<int> &arr, int n)
{
    unordered_set<int> s;

    for (int val : arr)
        s.insert(val);

    int ans = 0;

    for (int val : arr)
    {
        if (s.find(val - 1) == s.end())
        {
            int current = val;
            int cnt = 1;

            while (s.find(current + 1) != s.end())
            {
                current++;
                cnt++;
            }

            ans = max(ans, cnt);
        }
    }

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<int> arr =
        {
            100, 4, 200, 1, 3, 2};

    int n = arr.size();

    vector<int> arr1 = arr;
    cout << "Brute Force : "
         << lengthOfLongestConsecutiveSequenceBruteForce(arr1, n)
         << endl;

    vector<int> arr2 = arr;
    cout << "Better : "
         << lengthOfLongestConsecutiveSequenceBetter(arr2, n)
         << endl;

    vector<int> arr3 = arr;
    cout << "Optimal : "
         << lengthOfLongestConsecutiveSequenceOptimal(arr3, n)
         << endl;

    return 0;
}