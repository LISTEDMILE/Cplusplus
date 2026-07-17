#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int invCount = 0;
    int i = st, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[st + idx] = temp[idx];
    }
    return invCount;
}

int countInversionOptimal(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        int leftCount = countInversionOptimal(arr, st, mid);
        int rightCount = countInversionOptimal(arr, mid + 1, end);
        int invCount = merge(arr, st, mid, end);
        return leftCount + rightCount + invCount;
    }
    return 0;
}

vector<vector<int>> countInversionBruteForce(vector<int> &arr)
{
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                vector<int> temp = {arr[i], arr[j]};
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {6, 3, 5, 2, 7};
    vector<vector<int>> ans = countInversionBruteForce(arr);

    for (auto val : ans)
    {
        for (int val1 : val)
        {
            cout << val1 << " ";
        }
        cout << endl;
    }

    int ansOptimalCount = countInversionOptimal(arr, 0, arr.size() - 1);

    cout << "The no. of Inversion Count : " << ansOptimalCount;

    return 0;
}