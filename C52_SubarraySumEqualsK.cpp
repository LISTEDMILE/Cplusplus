#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int findSumCount(vector<int> &arr, int tar)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == tar)
            {
                count++;
            }
        }
    }
    return count;
}

int findSumCountOptimized(vector<int> &arr, int tar)
{
    int n = arr.size();
    int count = 0;
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    unordered_map<int, int> m;
    for (int j = 0; j < n; j++)
    {
        if (prefixSum[j] == tar)
        {
            count++;
        }
        int val = prefixSum[j] - tar;
        if (m.find(val) != m.end())
        {
            count += m[val];
        }
        if (m.find(prefixSum[j]) == m.end())
        {
            m[prefixSum[j]] = 0;
        }
        m[prefixSum[j]] = m[prefixSum[j]] + 1;
    }
    return count;
}

int main()
{

    vector<int> arr = {9, 4, 20, 3, 10, 5};
    int target = 33;

    int ans = findSumCount(arr, target);
    cout << "The no. of subarrays are : " << ans;

    int ansOptimized = findSumCountOptimized(arr, target);
    cout << "\nThe no. of subarrays are (Optimized): " << ansOptimized;
    return 0;
}