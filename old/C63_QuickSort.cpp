#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int st, int end)
{
    int pivot = arr[end];
    int idx = st;
    for (int j = st; j <= end - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[j], arr[idx++]);
        }
    }
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivotIdx = partition(arr, st, end);
        quickSort(arr, st, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, end);
    }
}

int main()
{

    vector<int> arr = {3, 4, 2, 5, 6, 2, 4};

    quickSort(arr, 0, arr.size() - 1);
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}