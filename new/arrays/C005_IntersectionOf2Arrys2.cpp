#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Intersection of Two Arrays II
// ===============================================================
//
// We need to return the intersection of two arrays.
//
// Difference from Intersection of Two Arrays:
//
// Here duplicates ARE allowed.
//
// Example:
//
// nums1 = {1,2,2,1}
// nums2 = {2,2}
//
// Answer = {2,2}
//
// ===============================================================

// ---------------------------------------------------------------
// Brute Force
// ---------------------------------------------------------------
//
// For every element of nums1, search for the same element
// in nums2.
//
// Once an element is used, mark it as visited so that
// the same occurrence cannot be used again.
//
// Time Complexity : O(n * m)
// Space Complexity : O(m)
// ---------------------------------------------------------------

vector<int> intersectBruteForce(vector<int> &nums1,
                                vector<int> &nums2)
{
    int n = nums1.size();

    int m = nums2.size();

    vector<int> visited(m, 0);

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] == nums2[j] &&
                visited[j] == 0)
            {
                ans.push_back(nums1[i]);

                visited[j] = 1;

                break;
            }
        }
    }

    return ans;
}

// ---------------------------------------------------------------
// Optimal
// ---------------------------------------------------------------
//
// Sort both arrays.
//
// Use two pointers:
//
// i -> nums1
// j -> nums2
//
// If nums1[i] == nums2[j]:
//      Add it to answer.
//      Move both pointers.
//
// If nums1[i] < nums2[j]:
//      Move i.
//
// Otherwise:
//      Move j.
//
// Since every occurrence is processed individually,
// duplicates are automatically handled.
//
// Time Complexity : O(n log n + m log m)
// Space Complexity : O(1) excluding the answer
// ---------------------------------------------------------------

vector<int> intersectOptimal(vector<int> &nums1,
                             vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());

    sort(nums2.begin(), nums2.end());

    int i = 0;

    int j = 0;

    int n = nums1.size();

    int m = nums2.size();

    vector<int> ans;

    while (i < n && j < m)
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);

            i++;

            j++;
        }
        else if (nums1[i] < nums2[j])

            i++;

        else

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
            1, 2, 2, 1};

    vector<int> nums2 =
        {
            2, 2};

    vector<int> ans1 =
        intersectBruteForce(nums1, nums2);

    cout << "Intersection (Brute Force) : ";

    printArray(ans1);

    vector<int> ans2 =
        intersectOptimal(nums1, nums2);

    cout << "Intersection (Optimal) : ";

    printArray(ans2);

    return 0;
}