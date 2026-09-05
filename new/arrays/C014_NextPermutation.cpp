#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Next Permutation
// ===============================================================
//
// Find the next lexicographically greater permutation.
//
// Example:
//
// {1,2,3} -> {1,3,2}
//
// If the array is already the largest permutation:
//
// {3,2,1} -> {1,2,3}
//
// ===============================================================

// ---------------------------------------------------------------
// 1. Brute Force
// ---------------------------------------------------------------
//
// Generate all permutations, sort them, and find the next
// permutation after the given one.
//
// Time Complexity : O(n! * n)
// Space Complexity : O(n! * n)
// ---------------------------------------------------------------

vector<int> nextPermutationBruteForce(vector<int> permutation, int n)
{
    vector<vector<int>> all;

    sort(permutation.begin(), permutation.end());

    do
    {
        all.push_back(permutation);
    } while (next_permutation(permutation.begin(), permutation.end()));

    for (int i = 0; i < all.size(); i++)
    {
        if (all[i] == permutation)
        {
            if (i + 1 < all.size())
                return all[i + 1];

            return all[0];
        }
    }

    return permutation;
}

// ---------------------------------------------------------------
// 2. Optimal
// ---------------------------------------------------------------
//
// Step 1:
// Find the first element from the right which is smaller than
// the element after it.
//
// This is the breakpoint.
//
// Step 2:
// If no breakpoint exists, the array is in descending order.
// Simply reverse it.
//
// Step 3:
// Find the smallest element from the right which is greater
// than the breakpoint and swap them.
//
// Step 4:
// Reverse the remaining part because it is in descending order.
//
// Time Complexity : O(n)
// Space Complexity : O(1)
// ---------------------------------------------------------------

vector<int> nextPermutationOptimal(vector<int> &permutation, int n)
{
    int elIdx = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (permutation[i] < permutation[i + 1])
        {
            elIdx = i;

            break;
        }
    }

    if (elIdx == -1)
    {
        reverse(permutation.begin(), permutation.end());

        return permutation;
    }

    for (int i = n - 1; i >= elIdx; i--)
    {
        if (permutation[i] > permutation[elIdx])
        {
            swap(permutation[elIdx], permutation[i]);

            break;
        }
    }

    reverse(permutation.begin() + elIdx + 1, permutation.end());

    return permutation;
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
    vector<int> permutation =
        {
            1, 2, 3};

    int n = permutation.size();

    vector<int> ans1 =
        nextPermutationBruteForce(permutation, n);

    cout << "Brute Force : ";

    printArray(ans1);

    vector<int> ans2 =
        nextPermutationOptimal(permutation, n);

    cout << "Optimal : ";

    printArray(ans2);

    return 0;
}