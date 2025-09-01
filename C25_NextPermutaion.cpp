#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lexicographicalNext(vector<int> arr)
{
    int len = arr.size();
    int pivot = -1;
    for (int i = len - 1; i > 0; i--)
    {
        if (arr[i - 1] < arr[i])
        {
            pivot = i - 1;
            break;
        }
    }
    

    if (pivot == -1)
    {
         reverse(arr.begin(), arr.end());
        return (arr);
    }

    for (int i = len - 1; i > pivot; i--)
    {
        if (arr[pivot] < arr[i])
        {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    int i = pivot + 1, j = len - 1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    return arr;
}

int main()
{

    // lexicographically next arrange ment matlab jaise 1 2 3 h to iske sare arrangements aur order me like 123 se bda 132 se bda 213 aise me se hme next wala dena h like 123 ka 132 .......
    vector<int> arr = {1, 2, 3, 5, 9, 8};
    vector<int> ans = lexicographicalNext(arr);

    cout << "Arr : ";
    for (int val : arr)
    {
        cout << val << " ";
    }

    cout << "\nAns : ";
    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}