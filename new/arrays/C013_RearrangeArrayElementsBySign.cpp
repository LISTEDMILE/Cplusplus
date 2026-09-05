#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Rearrange Array Elements by Sign
// ===============================================================
//
// Rearrange the array such that:
//
// positive, negative, positive, negative...
//
// The number of positive and negative elements is equal.
//
// Example:
//
// nums = {3,1,-2,-5,2,-4}
//
// Answer = {3,-2,1,-5,2,-4}
//
// ===============================================================

// ---------------------------------------------------------------
// 1. Brute Force
// ---------------------------------------------------------------
//
// Store positive and negative elements separately.
// Then place them alternately in the answer.
//
// Time Complexity : O(n)
// Space Complexity : O(n)
// ---------------------------------------------------------------

vector<int> rearrangeArrayBruteForce(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;

    for (int val : nums)
    {
        if (val > 0)
            pos.push_back(val);
        else
            neg.push_back(val);
    }

    vector<int> ans;

    for (int i = 0; i < pos.size(); i++)
    {
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
    }

    return ans;
}

// ---------------------------------------------------------------
// 2. Better
// ---------------------------------------------------------------
//
// First store positive and negative elements separately.
// Then directly place them at their required positions.
//
// This avoids repeated push_back operations.
//
// Time Complexity : O(n)
// Space Complexity : O(n)
// ---------------------------------------------------------------

vector<int> rearrangeArrayBetter(vector<int> &nums)
{
    int n = nums.size();

    vector<int> pos;
    vector<int> neg;

    for (int val : nums)
    {
        if (val > 0)
            pos.push_back(val);
        else
            neg.push_back(val);
    }

    vector<int> ans(n);

    int posIdx = 0;
    int negIdx = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            ans[i] = pos[posIdx++];
        else
            ans[i] = neg[negIdx++];
    }

    return ans;
}

// ---------------------------------------------------------------
// 3. Optimal
// ---------------------------------------------------------------
//
// Since positive elements must occupy even indices and negative
// elements must occupy odd indices, we can directly place every
// element in one pass.
//
// pos -> 0, 2, 4, ...
// neg -> 1, 3, 5, ...
//
// No need to create separate positive and negative arrays.
//
// Time Complexity : O(n)
// Space Complexity : O(n) for the answer
// ---------------------------------------------------------------

vector<int> rearrangeArrayOptimal(vector<int> &nums)
{
    vector<int> ans(nums.size());

    int pos = 0;

    int neg = 1;

    for (int val : nums)
    {
        if (val > 0)
        {
            ans[pos] = val;

            pos += 2;
        }
        else
        {
            ans[neg] = val;

            neg += 2;
        }
    }

    return ans;
}

// ===============================================================
// Print Array
// ===============================================================

void printArray(vector<int> &ans)
{
    for (int val : ans)

        cout << val << " ";

    cout << endl;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<int> nums =
        {
            3, 1, -2, -5, 2, -4};

    vector<int> ans1 =
        rearrangeArrayBruteForce(nums);

    cout << "Brute Force : ";

    printArray(ans1);

    vector<int> ans2 =
        rearrangeArrayBetter(nums);

    cout << "Better : ";

    printArray(ans2);

    vector<int> ans3 =
        rearrangeArrayOptimal(nums);

    cout << "Optimal : ";

    printArray(ans3);

    return 0;
}