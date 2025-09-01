#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bruteForced(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    return arr;
}

vector<int> optimised(vector<int> arr)
{
    int zero = 0, one = 0, two = 0;

    for (int val : arr)
    {
        if (val == 0)
        {
            zero++;
        }
        else if (val == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }

    int idx = 0;
    for (int i = idx; i < zero+idx; i++){
        arr[i] = 0;
    }
    idx = zero + idx;

    for (int i = idx; i < one+idx; i++){
        arr[i] = 1;
    }
    idx = one + idx;

    for (int i = idx; i < two+idx; i++){
        arr[i] = 2;
    }
    idx = two + idx;

    return arr;
}


// Dutch National Flag Algorithm
// isme hm teen partition me batke karenge aur jo unsorted array hogi wo in teen se hatke mid or high ke beech me hogi...
vector<int> mostOptimised(vector<int> arr)
{
    int len = arr.size();

    int mid = 0;
    int low = 0;
    int high = len-1;

    while(mid<=high){
        if (arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    return arr;
}

int main()
{

    vector<int> arr = {1, 2, 0, 0, 2, 1, 1, 0, 2, 1, 2, 0};
    vector<int> ansBruteForce = bruteForced(arr);
    vector<int> ansOptimised = optimised(arr);
    vector<int> ansMostOptimised = mostOptimised(arr);

    cout << "Arr : ";
    for (int val : arr)
    {
        cout << val << " ";
    }

    cout << "\nSorted by BruteForce : ";
    for (int val : ansBruteForce)
    {
        cout << val << " ";
    }

    cout << "\nSorted by optimised :";
    for (int val : ansOptimised)
    {
        cout << val << " ";
    }

    cout << "\nSorted by mostOptimised :";
    for (int val : ansMostOptimised)
    {
        cout << val << " ";
    }

    return 0;
}