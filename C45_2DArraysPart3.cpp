#include <iostream>
#include <vector>

using namespace std;

bool findEle(vector<vector<int>> arr, int target)
{

    int m = arr.size();
    int n = arr[0].size();

    int r = 0;
    int col = n - 1;
    while (r < m && col >= 0)
    {
        if (arr[r][col] == target)
        {
            return true;
        }
        else if (arr[r][col] > target)
        {
            col--;
        }
        else
        {
            r++;
        }
    }
    return false;
}

int main()
{

    /// searching take sorted array but this time the array is sorted like rowwise and colwise  ....
    vector<vector<int>> arr = {{2, 5, 6}, {3, 7, 8}, {19, 12, 66}};
    int target = 3;

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