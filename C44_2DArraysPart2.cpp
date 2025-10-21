#include <iostream>
#include <vector>

using namespace std;

bool searchInRow(vector<vector<int>> arr, int target, int mid)
{
    int n = arr[0].size();
    int st = 0;
    int end = n - 1;
    while (st <= end)
    {
        int middle = st + (end - st) / 2;
        if (arr[mid][middle] == target)
        {
            return true;
        }
        else if (arr[mid][middle] > target)
        {
            end = middle - 1;
        }
        else
        {
            st = middle + 1;
        }
    }
    return false;
}

bool findEle(vector<vector<int>> arr, int target)
{

    int m = arr.size();
    int n = arr[0].size();

    int st = 0;
    int end = m - 1;
    while (end >= st)
    {
        int mid = st + (end - st) / 2;
        if (target >= arr[mid][0] && target <= arr[mid][n - 1])
        {
            return searchInRow(arr, target, mid);
        }
        else if (target > arr[mid][n - 1])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

int main()
{

    /// searching take sorted array ....
    vector<vector<int>> arr = {{2, 5, 6}, {12, 24, 25}, {56, 65, 66}};
    int target = 25;

    // kya karenge same binary search pehle pta karenge konsi row me h binary search se fir us particular row me konsa elemnt h ye dekhenge.....
    bool ans = findEle(arr, target);
    if (ans)
    {
        cout << "Element is Present . ";
    }
    else
    {
        cout << "Element is not Present . ";
    }

    return 0;
}