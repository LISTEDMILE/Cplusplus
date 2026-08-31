#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Move Zeroes
// ===============================================================
//
// Move all zeroes to the end of the array while maintaining
// the relative order of the non-zero elements.
//
// Example:
//
// {0,1,0,3,12}
//
// becomes
//
// {1,3,12,0,0}
//
// Idea:
//
// j -> Position where the next non-zero element should be placed.
//
// count -> Number of zeroes in the array.
//
// First pass:
// Put all non-zero elements at the front.
//
// Second pass:
// Fill the remaining positions with zeroes.
//
// Time Complexity : O(n)
// Space Complexity : O(1)
// ===============================================================

void moveZeroes(vector<int> &nums)
{
    int j = 0;

    int count = 0;

    int n = nums.size();

    // -----------------------------------------------------------
    // Move all non-zero elements to the front
    // -----------------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)

            count++;

        else

            nums[j++] = nums[i];
    }

    // -----------------------------------------------------------
    // Fill remaining positions with zeroes
    // -----------------------------------------------------------

    for (int i = j; i < j + count; i++)

        nums[i] = 0;
}

// ===============================================================
// Print Array
// ===============================================================

void printArray(vector<int> &nums)
{
    for (int it : nums)

        cout << it << " ";

    cout << endl;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<int> nums =
        {
            0, 1, 0, 3, 12};

    cout << "Before: ";

    printArray(nums);

    moveZeroes(nums);

    cout << "After : ";

    printArray(nums);

    return 0;
}