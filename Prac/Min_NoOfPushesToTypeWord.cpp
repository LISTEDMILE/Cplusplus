#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

// ===============================================================
// Minimum Number of Pushes to Type Word II
// ===============================================================
//
// We have a mobile keypad with:
//
// • Each key can contain up to 8 letters.
//
// • The first 8 assigned letters require
//   1 push.
//
// • The next 8 assigned letters require
//   2 pushes.
//
// • The next 8 assigned letters require
//   3 pushes, and so on.
//
// Goal:
//
// Minimize the total number of pushes
// required to type the given word.
//
// Idea:
//
// 1. Count the frequency of every
//    distinct character.
//
// 2. Store frequencies in a Max Heap.
//
// 3. The most frequent characters
//    should require the fewest pushes.
//
// 4. Every group of 8 characters
//    increases the number of pushes
//    by one.
//
// Time Complexity : O(N log 26)
//
// Space Complexity : O(26)
// ===============================================================

int minimumPushes(string word)
{
    unordered_map<char, int> m;

    priority_queue<pair<int, char>> q;

    // -----------------------------------------------------------
    // Count Frequency
    // -----------------------------------------------------------

    for (char a : word)

        m[a]++;

    // -----------------------------------------------------------
    // Push Frequencies into Max Heap
    // -----------------------------------------------------------

    for (auto it : m)
    {
        q.push({it.second, it.first});
    }

    int ans = 0;

    int count = 0;

    // -----------------------------------------------------------
    // Assign Characters to Keypad
    // -----------------------------------------------------------

    while (!q.empty())
    {
        ans += q.top().first * (int(count / 8) + 1);

        count++;

        q.pop();
    }

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main()
{
    string word = "aabbccddeeffgghhiiii";

    cout << "Minimum Pushes : "
         << minimumPushes(word);

    return 0;
}