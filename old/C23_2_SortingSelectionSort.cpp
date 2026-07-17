#include <iostream>
#include <vector>
using namespace std;

vector<int> SelectionSort(vector<int> arr)
{
    int len = arr.size();

    for (int i = 0; i < len - 1; i++)
    {
        int smallestIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
    }
    return arr;
}

int main()
{

    vector<int> arr = {2, 5, 4, 6, 3};
    vector<int> ans = SelectionSort(arr);

    cout << "Unsorted array : ";
    for (int val : arr)
    {
        cout << val << " ";
    }

    cout << "\nSelection Sort : ";
    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}