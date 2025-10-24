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

set<vector<int>> find3SumOptimized(vector<int> arr)
{
    set<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        int tar = arr[i];
        set<int> s;
        for (int j = i + 1; j < arr.size(); j++)
        {
            int third = -(tar + arr[j]);
            if (s.find(third) != s.end())
            {
                vector<int> trip = {arr[i], arr[j], third};
                sort(trip.begin(), trip.end());
                ans.insert(trip);
            }
            s.insert(arr[j]);
        }
    }
    return ans;
}

set<vector<int>> find3SumMostOptimized(vector<int> arr)
{
    set<vector<int>> ans;

    // going to use 2 pointers approach so first sorting it..
    sort(arr.begin(), arr.end());
    int n = arr.size();
    // take each idx value and then apply 2 pointers approach on rest to find matching sum here 0.
    for (int i = 0; i < n; i++)
    {
        // without this also works but think of situation where there are multiple same values it will behave just like prev one so to ignore same triplate we skit this idx and find a new one.
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.insert({arr[i], arr[j], arr[k]});
                // yha bhi ek k-- se chlega but again imagine k-- kiya to 1st option wo bhi triplate bna le same j ke liye par 2 value j aur i wali whi h uske sath bhi triplate aur prev. k pe bhi matlab dono k same hi h . ya 2nd option nhi bna rha triplate to fir faeda hi kya ek iteration waste karne ka to sath sath j++ bhi kar diya.....
                k--;
                j++;

                // same as i bina iske chlega but imagine repeating value waste of loop so jab tak same arr[j] milra same triplate milenge to skip that part..
                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
            }
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

    set<vector<int>> ansMostOptimized = find3SumMostOptimized(arr);
    for (vector<int> val : ansMostOptimized)
    {
        for (int item : val)
        {
            cout << item << "\t";
        }
        cout << endl;
    }
    return 0;
}