#include <bits/stdc++.h>
using namespace std;

/*
    ----------------------------------------------------------
    Longest Increasing Subsequence (LIS) - O(n log n)
    ----------------------------------------------------------

    Idea:
    -----
    We maintain a vector 'temp'.

    temp[i] = Smallest possible ending element of an increasing
              subsequence of length (i + 1).

    IMPORTANT:
    ----------
    temp DOES NOT necessarily store the actual LIS.
    It only helps us compute the LENGTH of the LIS.

    ----------------------------------------------------------
    Algorithm
    ----------------------------------------------------------

    Case 1:
    Current element is greater than the last element of temp.

        temp = [2, 3, 7]
        current = 10

        10 > 7

        Append it.

        temp = [2, 3, 7, 10]

    ------------------------------------------

    Case 2:
    Current element is smaller.

        temp = [2, 3, 7, 10]
        current = 5

        Find first element >= 5 using lower_bound()

        lower_bound points to 7

        Replace 7 with 5

        temp = [2, 3, 5, 10]

    Notice:
    We made the ending element smaller.

    This increases our chances of extending the subsequence later.

    ----------------------------------------------------------
    Time Complexity  : O(n log n)
    Space Complexity : O(n)
*/

int longestIncreasingSubsequence(vector<int> &nums)
{
    int n = nums.size();

    vector<int> temp;

    // First element always starts an increasing subsequence.
    temp.push_back(nums[0]);
    cout << "After processing " << nums[0] << " : ";

    cout << temp[0] << " ";

    cout << endl;

    for (int i = 1; i < n; i++)
    {
        /*
            If current element is greater than the last element,
            we can extend the longest subsequence.
        */
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
        }
        else
        {
            /*
                Find the first element >= nums[i]
                and replace it.

                lower_bound returns an iterator.
                Subtracting temp.begin() converts it to an index.
            */

            int idx = lower_bound(temp.begin(),
                                  temp.end(),
                                  nums[i]) -
                      temp.begin();

            temp[idx] = nums[i];
        }

        // Print temp after every iteration
        cout << "After processing " << nums[i] << " : ";

        for (int x : temp)
            cout << x << " ";

        cout << endl;
    }

    return temp.size();
}

int main()
{
    /*
        Fixed Input

        Expected LIS:

        2 -> 3 -> 7 -> 18

        Length = 4
    */

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Input Array:\n";

    for (int x : nums)
        cout << x << " ";

    cout << "\n\n";

    int ans = longestIncreasingSubsequence(nums);

    cout << "\nLength of LIS = " << ans << endl;

    return 0;
}