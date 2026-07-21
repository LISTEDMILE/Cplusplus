#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// ===============================================================
// Alien Dictionary
// ===============================================================
//
// We are given a dictionary containing
// words sorted according to an
// unknown (alien) language.
//
// We have to determine the order
// of characters in that language.
//
// Idea:
//
// Compare every pair of adjacent words.
//
// The first character where they differ
// gives the ordering.
//
// Example:
//
// abc
// abd
//
// c comes before d
//
// Create a directed graph using these
// relations.
//
// Perform Topological Sorting using DFS.
//
// Time Complexity : O(N * L + K + E)
//
// N -> Number of words
// L -> Average length of a word
// K -> Number of characters
// E -> Number of edges
//
// Space Complexity : O(K + E)
// ===============================================================

void helper(vector<int> adj[],
            vector<int> &visited,
            vector<int> &pathVisited,
            int idx,
            string &ans){

    visited[idx] = 1;
    pathVisited[idx] = 1;

    for(int it : adj[idx]){

        if(!visited[it])

            helper(adj,
                   visited,
                   pathVisited,
                   it,
                   ans);

        else if(pathVisited[it] == 1)

            return;
    }

    ans = ans + char(idx + 'a');

    pathVisited[idx] = 0;
}

string getAlienLanguage(vector<string> &dictionary,
                        int k){

    vector<int> adj[k];

    // -----------------------------------------------------------
    // Create Graph
    // -----------------------------------------------------------

    for(int i = 1; i < dictionary.size(); i++){

        string s1 = dictionary[i-1];

        string s2 = dictionary[i];

        int len = min(s1.size(), s2.size());

        for(int it = 0; it < len; it++){

            if(s1[it] != s2[it]){

                adj[s1[it]-'a'].push_back(s2[it]-'a');

                break;
            }
        }
    }

    // -----------------------------------------------------------
    // Topological Sort using DFS
    // -----------------------------------------------------------

    vector<int> visited(k,0);

    vector<int> pathVisited(k,0);

    string ans = "";

    for(int i = 0; i < k; i++){

        if(!visited[i])

            helper(adj,
                   visited,
                   pathVisited,
                   i,
                   ans);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

// ===============================================================
// Main
// ===============================================================

int main(){

    vector<string> dictionary =
    {
        "baa",
        "abcd",
        "abca",
        "cab",
        "cad"
    };

    int k = 4;

    cout<<"Alien Language Order : "
        <<getAlienLanguage(dictionary,k);

    return 0;
}