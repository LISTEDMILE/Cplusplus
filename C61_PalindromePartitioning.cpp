#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isPalin(string part)
{
    // by logic...

    // int str = 0;
    // int end = part.size()-1;
    // while(str < end){
    //     if(part[str] != part[end]){
    //         return false;
    //     }
    //     str++;
    //     end--;
    // }
    // return true;

    // by functions..
    string s = part;
    reverse(s.begin(), s.end());
    return s == part;
}

void getAllParts(string s, vector<vector<string>> &ans, vector<string> &partition)
{
    int n = s.size();
    if (n == 0)
    {
        ans.push_back({partition});
        return;
    }
    for (int i = 0; i < n; i++)
    {
        // 0 se i idx tak ki str
        string part = s.substr(0, i + 1);
        if (isPalin(part))
        {
            partition.push_back(part);
            
            // i se aage se suru string
            getAllParts(s.substr(i + 1), ans, partition);
            partition.pop_back();
        }
    }
}

vector<vector<string>> getPartitions(string str)
{
    vector<vector<string>> ans;
    vector<string> partition;

    getAllParts(str, ans, partition);
    return ans;
}

int main()
{

    string str = "aabb";
    vector<vector<string>> ans = getPartitions(str);
    for (auto val : ans)
    {
        for (string val1 : val)
        {
            cout << val1 << " ";
        }
        cout << endl;
    }
    return 0;
}