#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> BruteForce(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<int> Optimized(vector<int> arr, int target)
{
    unordered_map<int, int> m;
    vector<int> ans;

    // yha sec ko target ki help se pehle find karenge fir agar jo map create kiya uski help se index add kar denge ans me if present if not to is value ko index ke sath map me add kar lenge fir dobara run karenge..
    for (int i = 0; i < arr.size(); i++)
    {
        int first = arr[i];
        int sec = target - first;
        if (m.find(sec) != m.end())
        {

            ans.push_back(m[sec]);
            ans.push_back(i);
            return ans;
        }
        m[first] = i;
    }
    return {-1, -1};
}

int main()
{

    // we have to find the 2 elements whose sum is equal to target no.
    // . no 2 solution can exist
    // . cannot add the no to itself like 5+5 =10;

    vector<int> arr = {2, 5, 3, 34, 53};
    int target = 8;

    vector<int> ansBruteForce = BruteForce(arr, target);
    for (int val : ansBruteForce)
    {
        cout << val << "  ";
    }

    // we can also apply 2 pointers approach but have to sort first -- better approach....

    // now Optimized approach...
    vector<int> ansOptimized = Optimized(arr, target);
    for (int val : ansOptimized)
    {
        cout << val << "  ";
    }
    return 0;
}