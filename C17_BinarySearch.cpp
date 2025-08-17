#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid;
    while (start <= end)
    {
       // mid = (start + end) / 2;
        
       // if we add 2 intmax then mid will not be capable of holding it to cover it we can use ...
        mid = start + (end - start) / 2;
        //same as above...mathemetically...

        if (target == arr[mid])
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}


int findByRecursion(vector <int> arr, int target , int start , int end){
    int mid = start + (end - start) / 2;
    if(start > end){
        return -1;
    }
    if( arr[mid] == target ){
        return mid;
    }
    else if(arr[mid] > target){
        return findByRecursion(arr, target, start, mid - 1);
    }
    else if(arr[mid] < target){
        return findByRecursion(arr, target, mid + 1, end);
    }
}

int main()
{

    vector<int> arr = {-1, 4, 6, 7, 8, 12, 34, 55, 79};
    // always for sorted arrays....

    int target = 12;
    int ansIndex = find(arr, target);
    if (ansIndex == -1)
    {
        cout << target << " not found \n";
    }
    else
    {
        cout << target << " found at index : " << ansIndex << "\n";
    }


    // by recursion....
    cout << "\nBy recursion\n";
    int ansIndexByRecursion = findByRecursion(arr, target , 0, arr.size()-1);
    if (ansIndexByRecursion == -1)
    {
        cout << target << " not found \n";
    }
    else
    {
        cout << target << " found at index : " << ansIndexByRecursion << "\n";
    }

    return 0;
}