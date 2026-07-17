#include <iostream>
#include <vector>

using namespace std;

void getPerms(vector<int> &arr, int idx, vector<vector<int>> &ans, int size)
{
    if (idx == size)
    {
        ans.push_back({arr});
        return;
    }
    for (int i = idx; i < size; i++)  // yha hm apne original array me combinations bna rhe h
    {
        swap(arr[i], arr[idx]); // combinations bante rhenge arr ke jab tak idx == size nhi hota uske bad ans me add
        getPerms(arr, idx + 1, ans, size); // jo uper combination bne unke uper firse
        swap(arr[i], arr[idx]);  // jo combinations bne uper unko revert kardiya ( tree se imagine karo taki agli branch firse fresh se combination bna ske);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    int size = arr.size();
    getPerms(arr, 0, ans, size);
    for (auto val : ans)
    {
        for (int val1 : val)
        {
            cout << val1 << " ";
        }
        cout << "\n";
    }
    return 0;
}