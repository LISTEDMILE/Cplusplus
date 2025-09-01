#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(vector<int> arr)
{
    int len = arr.size();

    for (int i = 1; i < len; i++)
    {
        int curr = arr[i];
        int prevIndex = i - 1;
        while (arr[prevIndex] > curr && prevIndex >= 0)
        { 
            arr[prevIndex + 1] = arr[prevIndex];
            prevIndex--;
        }

        arr[prevIndex + 1] = curr;
    }
    return arr;
}

int main()
{

    vector<int> arr = {2, 5, 4, 6, 3};
    vector<int> ans = InsertionSort(arr);

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