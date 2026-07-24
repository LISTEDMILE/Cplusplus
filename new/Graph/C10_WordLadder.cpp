#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// ===============================================================
// Word Ladder
// ===============================================================
//
// We are given:
//
// beginWord
// endWord
// wordList
//
// We have to find the length of the
// shortest transformation sequence.
//
// Rules:
//
// • Only one character can be changed
//   at a time.
//
// • Every transformed word must exist
//   in the wordList.
//
// Idea:
//
// This is an unweighted graph problem.
//
// Every word represents a node.
//
// Two words are connected if they differ
// by exactly one character.
//
// Since every transformation has equal
// cost, BFS gives the shortest path.
//
// We use an unordered_set for
// O(1) lookup and erase words as soon
// as they are visited.
//
// Time Complexity : O(N × L × 26)
//
// N -> Number of words
// L -> Length of each word
//
// Space Complexity : O(N)
// ===============================================================

int ladderLength(string beginWord,
                 string endWord,
                 vector<string> &wordList)
{

    queue<pair<int, string>> q;

    int ans = 0;

    unordered_set<string> s(
        wordList.begin(),
        wordList.end());

    q.push({1, beginWord});

    s.erase(beginWord);

    while (!q.empty())
    {

        int len = q.front().first;

        string word = q.front().second;

        ans = len;

        q.pop();

        if (word == endWord)

            return ans;

        // -------------------------------------------------------
        // Generate all possible words
        // by changing one character
        // -------------------------------------------------------

        for (int it = 0; it < 26; it++)
        {

            int lenOfWord = word.size();

            for (int i = 0; i < lenOfWord; i++)
            {

                string test = word;

                test[i] = 'a' + it;

                if (s.find(test) != s.end())
                {

                    q.push({len + 1, test});

                    s.erase(test);
                }
            }
        }
    }

    return 0;
}

// ===============================================================
// Main
// ===============================================================

int main()
{

    string beginWord = "hit";

    string endWord = "cog";

    vector<string> wordList =
        {
            "hot",
            "dot",
            "dog",
            "lot",
            "log",
            "cog"};

    cout << "Shortest Transformation Length : "
         << ladderLength(beginWord,
                         endWord,
                         wordList);

    return 0;
}