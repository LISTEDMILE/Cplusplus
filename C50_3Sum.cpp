#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<vector<int>> find3Sum(vector<int> arr)
{
    set<vector<int>> s;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> triplate = {arr[i], arr[j], arr[k]};
                    sort(triplate.begin(), triplate.end());
                    s.insert(triplate);
                }
            }
        }
    }
    return s;
}

int main()
{

    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    set<vector<int>> ans = find3Sum(arr);
    for (vector<int> val : ans)
    {
        for (int item : val)
        {
            cout << item << "\t";
        }
        cout << endl;
    }

    return 0;
}