#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>> &arr, int row, int col, int n, int expectedVal)
{
    if (expectedVal == n * n)
    {
        return true;
    }
    
    if (row >= n || row < 0 || col >= n || col < 0 || arr[row][col] != expectedVal)
    {
        return false;
    }

    return (
        isValid(arr, row - 2, col + 1, n, expectedVal + 1) ||
        isValid(arr, row - 2, col - 1, n, expectedVal + 1) ||
        isValid(arr, row + 2, col + 1, n, expectedVal + 1) ||
        isValid(arr, row + 2, col - 1, n, expectedVal + 1) ||
        isValid(arr, row + 1, col + 2, n, expectedVal + 1) ||
        isValid(arr, row - 1, col + 2, n, expectedVal + 1) ||
        isValid(arr, row + 1, col - 2, n, expectedVal + 1) ||
        isValid(arr, row - 1, col - 2, n, expectedVal + 1)
    );
}

int main()
{
    vector<vector<int>> arr = {
                            {0, 21, 10, 15, 6},
                            {11, 16, 7, 20, 9},
                            {24, 1, 22, 5, 14},
                            {17, 12, 3, 8, 19},
                            {2, 23, 18, 13, 4}
                        };

    if (isValid(arr, 0, 0, arr.size(), 0))
    {
        cout << "Possible - Right config";
    }
    else
    {
        cout << "Not Possible - Wrong config";
    }
    return 0;
}