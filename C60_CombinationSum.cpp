#include <iostream>
#include <vector>

using namespace std;

void findCombinations(vector<int> &arr, int size, int i, vector<vector<int>> &ans, vector<int> &comb, int tar)
{

    // basically hm har idx ko 2 cheez kar rhe pehla add kiya comb me aur fir next idx pe nhi gye add to kiya but whi idx taki bar bar add ho ske.
    // uske bad  case ki nhi kiya comb me add to add mat karo idx bhda do..
    // matlab ek element jitna chahe utna add hoga first call ke acc. aur next ke according add nhi hoga sirf idx bhdega..

    // no. add karenge comb me aur tar ko ghatate rhenge jo bhi kiya ki ab rest kitna chahiye to wo niche check kiya ki if zero h matlab poora tar aa chuka...
    if (tar == 0)
    {
        ans.push_back({comb});
        return;
    }
    if (i == size || tar < 0)
    {
        return;
    }

    comb.push_back(arr[i]);
    // findCombinations(arr, size, i + 1, ans, comb, tar - arr[i]);
    findCombinations(arr, size, i, ans, comb, tar - arr[i]);
    comb.pop_back();
    findCombinations(arr, size, i + 1, ans, comb, tar);
}

int main()
{

    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> combination;
    int target = 6;
    findCombinations(arr, arr.size(), 0, ans, combination, target);
    for (auto val : ans)
    {
        for (int val1 : val)
        {
            cout << val1 << " ";
        }
        cout << endl;
    }
    return 0;
}