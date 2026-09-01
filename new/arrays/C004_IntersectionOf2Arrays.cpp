#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Intersection of Two Arrays
// ===============================================================
//
// Find all elements that are present in both arrays.
// Each element should appear only once.
//
// Example:
//
// nums1 = {4,9,5,9,9}
// nums2 = {9,4,9,8,4}
//
// Answer = {4,9}
//
// ===============================================================

// ---------------------------------------------------------------
// Brute Force
// ---------------------------------------------------------------
//
// For every element of nums1, search for it in nums2.
//
// visited is used so that the same element from nums2
// is not used again.
//
// Before adding an element, check whether it is already
// present in ans.
//
// Time Complexity : O(n * m)
// Space Complexity : O(m + n)
// ---------------------------------------------------------------

vector<int> intersectionBruteForce(vector<int> &nums1,
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
                if (ans.size() == 0 ||
                    ans.back() != nums1[i])
                {
                    ans.push_back(nums1[i]);
                }

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
// Sort both arrays and use two pointers.
//
// i -> nums1
// j -> nums2
//
// If equal:
//      add the element.
//
// If nums1[i] < nums2[j]:
//      move i.
//
// Otherwise:
//      move j.
//
// Since we need unique elements,
// check ans.back() before inserting.
//
// Time Complexity : O(n log n + m log m)
// Space Complexity : O(n + m) for the answer
// ---------------------------------------------------------------

vector<int> intersectionOptimal(vector<int> &nums1,
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
            if (ans.size() != 0 &&
                nums1[i] == ans.back())
            {
                i++;
                j++;

                continue;
            }

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
            4, 9, 5, 9, 9};

    vector<int> nums2 =
        {
            9, 4, 9, 8, 4};

    vector<int> ans1 =
        intersectionBruteForce(nums1, nums2);

    cout << "Intersection (Brute Force) : ";

    printArray(ans1);

    vector<int> ans2 =
        intersectionOptimal(nums1, nums2);

    cout << "Intersection (Optimal) : ";

    printArray(ans2);

    return 0;
}