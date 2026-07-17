#include <bits/stdc++.h>
using namespace std;

vector<int> printLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 0);
    vector<int> ans;
    int maxii = 1;
    int lastIndex = 0;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if (dp[i] > maxii)
        {
            maxii = dp[i];
            lastIndex = i;
        }
    }

    while (hash[lastIndex] != lastIndex)
    {
        ans.push_back(nums[lastIndex]);
        lastIndex = hash[lastIndex];
    }

    ans.push_back(nums[lastIndex]);

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    vector<int> nums = {3, 30, 2, 1, 56};

    vector<int> ans = printLIS(nums);

    cout << "Length of LIS : " << ans.size() << "\n";

    cout << "LIS : ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}