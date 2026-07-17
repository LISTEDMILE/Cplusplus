#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int st, int mid, int end) // O(n)
{
    vector<int> temp;
    int i = st;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
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
}

void mergeSort(vector<int> &arr, int st, int end) // O(log(n))
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end); // O(n)
    }
}

int main()
{

    vector<int> arr = {3, 4, 2, 5, 6, 2, 4};
    mergeSort(arr, 0, arr.size() - 1);
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}