#include <iostream>
#include <vector>

using namespace std;

void subSets(vector<int> &arr, vector<int> &ans, int i)
{
    if (i == arr.size())
    {
        for (int val : ans)
        {
            cout << val << ' ';
        }
        cout << endl;
        return;
    }
    // include
    ans.push_back(arr[i]);
    subSets(arr, ans, i + 1);

    // exclude
    ans.pop_back();
    subSets(arr, ans, i + 1);
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> ans;
    subSets(arr, ans, 0);
    return 0;
}