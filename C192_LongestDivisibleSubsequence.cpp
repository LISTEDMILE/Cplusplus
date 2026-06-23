
#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
Longest Divisible Subset (LeetCode 368)

Time Complexity  : O(n²)
Space Complexity : O(n)

Idea:
This problem is exactly like "Print LIS".

LIS Condition:
    nums[i] > nums[j]

Divisible Subset Condition:
    nums[i] % nums[j] == 0

Instead of checking increasing order,
we check divisibility.
------------------------------------------------------------
*/

vector<int> largestDivisibleSubset(vector<int> nums)
{
    int n = nums.size();

    /*
        Sorting is compulsory.

        Why?

        After sorting,

            nums[j] <= nums[i]

        Therefore if nums[i] is divisible by nums[j],
        then nums[j] can safely come before nums[i]
        in the subset.

        Without sorting, the DP relation breaks.
    */

    sort(nums.begin(), nums.end());

    /*
        dp[i]

        Length of the largest divisible subset
        ending at index i.
    */

    vector<int> dp(n, 1);

    /*
        parent[i]

        Stores the previous index used to build
        the subset.

        Initially every element points to itself,
        meaning every element alone forms a subset
        of length 1.
    */

    vector<int> parent(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int maxi = 1;      // Stores maximum subset length.
    int lastIndex = 0; // Ending index of the largest subset.

    /*
        Build DP.

        For every element,
        check all previous elements.

        If current number is divisible by a previous
        number, then we can extend that subset.
    */

    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            /*
                Can we extend the subset ending at prev?

                Two conditions:

                1) Divisible
                2) Gives a longer subset
            */

            if (nums[i] % nums[prev] == 0 &&
                dp[prev] + 1 > dp[i])
            {
                dp[i] = dp[prev] + 1;

                // Store where we came from.
                parent[i] = prev;
            }
        }

        /*
            Update the longest subset found so far.
        */

        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    /*
        Reconstruct the answer.

        Start from the last element of the subset
        and keep following parent[] until an element
        points to itself.

        Example:

            parent

            0
            ↑
            1
            ↑
            3
            ↑
            5

        Start from 5

            5 -> 3 -> 1 -> 0

        Reverse it at the end.
    */

    vector<int> ans;

    while (parent[lastIndex] != lastIndex)
    {
        ans.push_back(nums[lastIndex]);

        lastIndex = parent[lastIndex];
    }

    // Push the first element.
    ans.push_back(nums[lastIndex]);

    // Reverse because reconstruction was backwards.
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    // Fixed input for practice.
    vector<int> nums = {1, 16, 7, 8, 4, 2};

    vector<int> ans = largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset:\n";

    for (int x : ans)
        cout << x << " ";

    cout << endl;
}
