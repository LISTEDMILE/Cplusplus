#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> arr)
{
    int len = arr.size();

    for (int i = 0; i < len - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return arr;
        }
    }
    return arr;
}

int main()
{

    vector<int> arr = {2, 5, 4, 6, 3};
    vector<int> ans = bubbleSort(arr);

    cout << "Unsorted array : ";
    for (int val : arr)
    {
        cout << val << " ";
    }

    cout << "\nBubble Sort : ";
    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}