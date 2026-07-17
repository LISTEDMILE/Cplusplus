#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMinPathByRecursion(vector<int> &arr, int idx, int k)
{ // O(k^n) space -O(n)
    if (idx == 0)
    {
        return 0;
    }

    int minn = INT16_MAX;
    for (int i = 1; i <= k; i++)
    {
        if ((idx - i) >= 0)
        {
            minn = min(minn, (findMinPathByRecursion(arr, idx - i, k) + abs(arr[idx] - arr[idx - i])));
        }
    }

    return minn;
}

int findMinPathOptimalMemoization(vector<int> &arr, int idx, vector<int> &p, int k)
{ // O(n*k) space -O(n+n)
    if (idx == 0)
    {
        return 0;
    }

    if (p[idx] != -1)
    {
        return p[idx];
    }

    int minn = INT16_MAX;
    for (int i = 1; i <= k; i++)
    {
        if ((idx - i) >= 0)
        {
            minn = min(minn, findMinPathOptimalMemoization(arr, idx - i, p, k) + abs(arr[idx] - arr[idx - i]));
        }
    }

    return p[idx] = minn;
}

int findMinPathOptimalTabular(vector<int> &arr, int n, vector<int> &p, int k)
{ // O(n*k) space -O(n)

    p[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minn = INT16_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                minn = min(minn, (abs(arr[i - j] - arr[i]) + p[i - j]));
            }
        }
        p[i] = minn;
    }
    return p[n - 1];
}

int main()
{
    vector<int> arr =
        {1, 45, 4, 3, 23, 50, 60, 100, 9, 2};
    int k = 4;

    cout << "Minimum distance (Recursion) : " << findMinPathByRecursion(arr, arr.size() - 1, k);

    vector<int> p(arr.size(), -1);

    cout << "\nMinimum distance (Memoization) : " << findMinPathOptimalMemoization(arr, arr.size() - 1, p, k);

    fill(p.begin(), p.end(), -1);

    cout << "\nMinimum distance (Tabulation) : " << findMinPathOptimalTabular(arr, arr.size(), p, k);

    return 0;
}