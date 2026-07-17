#include <iostream>
#include <vector>

using namespace std;

void subSets(vector<int> &arr, vector<int> &ans, int i, vector<vector<int>> &allSubSets)
{
    if (i == arr.size())
    {
        allSubSets.push_back({ans});
        return;
    }
    // include
    ans.push_back(arr[i]);
    subSets(arr, ans, i + 1, allSubSets);

    // exclude
    ans.pop_back();
    subSets(arr, ans, i + 1, allSubSets);
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> ans;
    vector<vector<int>> allSubSets;
    subSets(arr, ans, 0, allSubSets);

    for (auto val : allSubSets)
    {
        for (int valI : val)
        {
            cout << valI << ' ';
        }
        cout << endl;
    }
    return 0;
}