#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Leaders in an Array
// ===============================================================
//
// An element is called a leader if it is greater than all the
// elements to its right.
//
// The last element is always a leader.
//
// Example:
//
// elements = {10, 22, 12, 3, 0, 6}
//
// Leaders = {22, 12, 6}
//
// ===============================================================

// ---------------------------------------------------------------
// 1. Brute Force
// ---------------------------------------------------------------
//
// For every element, check all elements to its right.
//
// Time Complexity : O(n²)
// Space Complexity : O(n)
// ---------------------------------------------------------------

vector<int> findLeadersBruteForce(vector<int> &elements, int n)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool leader = true;

        for (int j = i + 1; j < n; j++)
        {
            if (elements[j] >= elements[i])
            {
                leader = false;
                break;
            }
        }

        if (leader)
            ans.push_back(elements[i]);
    }

    return ans;
}

// ---------------------------------------------------------------
// 2. Better
// ---------------------------------------------------------------
//
// Use a suffix maximum array.
//
// suffixMax[i] stores the maximum element to the right of i.
//
// Then an element is a leader if it is greater than suffixMax[i].
//
// Time Complexity : O(n)
// Space Complexity : O(n)
// ---------------------------------------------------------------

vector<int> findLeadersBetter(vector<int> &elements, int n)
{
    vector<int> suffixMax(n);

    suffixMax[n - 1] = elements[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(elements[i + 1], suffixMax[i + 1]);
    }

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1 || elements[i] > suffixMax[i])
            ans.push_back(elements[i]);
    }

    return ans;
}

// ---------------------------------------------------------------
// 3. Optimal
// ---------------------------------------------------------------
//
// Traverse from right to left.
//
// lead stores the greatest element encountered so far.
//
// If elements[i] > lead, then elements[i] is a leader.
//
// Finally reverse the answer because we traversed from right
// to left.
//
// Time Complexity : O(n)
// Space Complexity : O(n)
// ---------------------------------------------------------------

vector<int> findLeadersOptimal(vector<int> &elements, int n)
{
    vector<int> ans;

    int lead = elements[n - 1];

    ans.push_back(lead);

    for (int i = n - 2; i >= 0; i--)
        if (elements[i] > lead)
        {
            ans.push_back(elements[i]);

            lead = elements[i];
        }

    reverse(ans.begin(), ans.end());

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
    vector<int> elements =
        {
            10, 22, 12, 3, 0, 6};

    int n = elements.size();

    vector<int> ans1 =
        findLeadersBruteForce(elements, n);

    cout << "Brute Force : ";

    printArray(ans1);

    vector<int> ans2 =
        findLeadersBetter(elements, n);

    cout << "Better : ";

    printArray(ans2);

    vector<int> ans3 =
        findLeadersOptimal(elements, n);

    cout << "Optimal : ";

    printArray(ans3);

    return 0;
}