#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<vector<int>> find4Sum(vector<int> &arr, int tar)
{
    sort(arr.begin(), arr.end());
    set<vector<int>> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[j - 1] && j > i + 1)
            {
                continue;
            }
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                // 4 max int ko add karenge to wo max int se jyada hoga obvious to long long lenge....
                // long long me add karne ke liye pehle explicitely convert karenge long long me aur firs store karenge...
                long long sum = (long long)arr[i] + (long long)arr[j] + (long long)arr[k] + (long long)arr[l];
                if (sum > tar)
                {
                    l--;
                }
                else if (sum < tar)
                {
                    k++;
                }
                else
                {
                    ans.insert({arr[i], arr[j], arr[k], arr[l]});
                    l--;
                    k++;

                    // my own created loop very very optimized but not yo use as it doesn't separates the logic very clearly so to see actual path see C50....
                    while (k < l)
                    {
                        if (arr[k] == arr[k - 1])
                        {
                            k++;
                        }
                        if (arr[l] == arr[l + 1])
                        {
                            l--;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, -1, 2, 2, -1, 1, -1};

    int target = 0;
    set<vector<int>> ans = find4Sum(arr, target);

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