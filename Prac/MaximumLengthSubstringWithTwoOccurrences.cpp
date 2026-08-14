#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> m;
        int n = s.size();

        int i = 0;
        int j = 0;
        int ans = 0;

        while(j < n){
            m[s[j]]++;

            while(m[s[j]] > 2)
                m[s[i++]]--;

            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    string s = "bcbbbcba";

    cout << "String: " << s << endl;
    cout << "Maximum Length: "
         << sol.maximumLengthSubstring(s) << endl;

    return 0;
}