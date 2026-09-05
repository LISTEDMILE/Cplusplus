#include <bits/stdc++.h>
using namespace std;

// ===============================================================
// Two Sum
// ===============================================================
//
// Find whether there exist two different elements whose sum
// is equal to target.
//
// 3 Approaches:
//
// 1. Brute Force
// 2. Hashing
// 3. Sorting + Two Pointer
//
// ===============================================================

// ---------------------------------------------------------------
// 1. Brute Force
// ---------------------------------------------------------------
//
// Check every possible pair.
//
// Time Complexity : O(n²)
// Space Complexity : O(1)
// ---------------------------------------------------------------

string readBruteForce(int n, vector<int> book, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (book[i] + book[j] == target)
                return "YES";
        }
    }

    return "NO";
}

// ---------------------------------------------------------------
// 2. Better
// Using Hashing
// ---------------------------------------------------------------
//
// For every element, check whether target - current element
// has already appeared.
//
// Time Complexity : O(n) average
// Space Complexity : O(n)
// ---------------------------------------------------------------

string readBetter(int n, vector<int> book, int target)
{
    unordered_map<int, bool> m;

    for (int val : book)
    {
        if (m.find(target - val) != m.end())
            return "YES";

        m[val] = true;
    }

    return "NO";
}

// ---------------------------------------------------------------
// 3. Optimal
// Sorting + Two Pointer
// ---------------------------------------------------------------
//
// Sort the array.
//
// i -> smallest element
// j -> largest element
//
// If sum is greater than target -> decrease j
// If sum is smaller than target -> increase i
//
// Time Complexity : O(n log n)
// Space Complexity : O(1) excluding sorting implementation
// ---------------------------------------------------------------

string readOptimal(int n, vector<int> book, int target)
{
    sort(book.begin(), book.end());

    int i = 0;

    int j = n - 1;

    while (i < j)
    {
        if (book[i] + book[j] == target)
            return "YES";

        else if (book[i] + book[j] > target)
            j--;

        else
            i++;
    }

    return "NO";
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    vector<int> book =
        {
            2, 6, 5, 8, 11};

    int n = book.size();

    int target = 14;

    cout << "Brute Force : "
         << readBruteForce(n, book, target)
         << endl;

    cout << "Hashing : "
         << readBetter(n, book, target)
         << endl;

    cout << "Sorting + Two Pointer : "
         << readOptimal(n, book, target)
         << endl;

    return 0;
}