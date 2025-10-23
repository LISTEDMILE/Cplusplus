#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// using unordered_set can also do but set provide default hashing functions we hvae to create custom hashing ......

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
                    if (s.find(triplate) == s.end())
                    {
                        s.insert(triplate);
                    }
                }
            }
        }
    }
    return s;
}

set<vector<int>> find3SumOptimized(vector<int> arr){
   
    set<vector<int>> ans;
    for (int i = 0; i < arr.size();i++){
        int tar = arr[i];
         set<int> s;
        for (int j = i + 1; j < arr.size();j++){
            int third = -(tar + arr[j]);
            if(s.find(third) != s.end()){
                vector<int> trip = {arr[i], arr[j], third};
                sort(trip.begin(), trip.end());
                ans.insert(trip);
            }
            s.insert(arr[j]);
        }
    }
    return ans;
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

    set<vector<int>> ansOptimized = find3SumOptimized(arr);
    for (vector<int> val : ansOptimized)
    {
        for (int item : val)
        {
            cout << item << "\t";
        }
        cout << endl;
    }
    return 0;
}