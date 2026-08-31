#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Union of Two Sorted Arrays
// ===============================================================
//
// Given two sorted arrays, find their union.
//
// Union means:
// - All elements from both arrays
// - No duplicate elements
// - Result remains sorted
//
// Approach:
// Use two pointers.
//
// i -> points to nums1
// j -> points to nums2
//
// At every step, take the smaller element.
// Before inserting, check the last element of ans
// to avoid duplicates.
//
// Time Complexity : O(n + m)
// Space Complexity : O(n + m)
// ===============================================================

vector<int> sortedArray(vector<int> nums1,
                        vector<int> nums2)
{
    int i = 0;

    int j = 0;

    int n = nums2.size();

    int m = nums1.size();

    vector<int> ans;

    // -----------------------------------------------------------
    // Take the first element
    // -----------------------------------------------------------

    if (nums1[i] < nums2[j])

        ans.push_back(nums1[i++]);

    else

        ans.push_back(nums2[j++]);

    // -----------------------------------------------------------
    // Compare both arrays
    // -----------------------------------------------------------

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            if (ans.back() != nums1[i])

                ans.push_back(nums1[i]);

            i++;
        }
        else
        {
            if (ans.back() != nums2[j])

                ans.push_back(nums2[j]);

            j++;
        }
    }

    // -----------------------------------------------------------
    // Remaining elements of nums1
    // -----------------------------------------------------------

    while (i < m)
    {
        if (ans.back() != nums1[i])

            ans.push_back(nums1[i]);

        i++;
    }

    // -----------------------------------------------------------
    // Remaining elements of nums2
    // -----------------------------------------------------------

    while (j < n)
    {
        if (ans.back() != nums2[j])

            ans.push_back(nums2[j]);

        j++;
    }

    return ans;
}

// ===============================================================
// Print Array
// ===============================================================

void printArray(vector<int> &ans)
{
    for (int it : ans)

        cout << it << " ";

    cout << endl;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<int> nums1 =
        {
            1, 2, 2, 3, 4};

    vector<int> nums2 =
        {
            2, 3, 5, 6};

    vector<int> ans =
        sortedArray(nums1, nums2);

    cout << "Union : ";

    printArray(ans);

    return 0;
}