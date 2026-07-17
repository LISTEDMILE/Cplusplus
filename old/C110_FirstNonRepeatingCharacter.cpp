#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int firstNonRepeatingCharacter(string s)
{
    unordered_map<char, int> m;
    queue<int> q;
    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) == m.end())
        {
            q.push(i);
            m[s[i]] = 1;
        }
        else
        {
            m[s[i]]++;
        }
    }

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        if (m[s[idx]] == 1)
        {
            return idx;
        }
    }
    return -1;
}

int main()
{
    string s = "abaacttcn";
    int idx = firstNonRepeatingCharacter(s);
    if (idx != -1)
        cout << "The first Non Repeating Character : " << s[idx] << " at index : " << idx;
    else
        cout << "No non Repeating Character";
    return 0;
}