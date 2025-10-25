#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // isme array sorted hogi but as a loop uske last element first me aae fir baki aage traverse fir last se ek aur fir traverse aise hogya..

    // ab kya karenge ki same mid element nikalenge ab circlular sorted array me ek side dekhenge to ab bhi sorted hi hogi to pehle pta karenge konsi side sorted h fir pta karenge ki us area me target h? if yes to next array wo hogi warna doosri side wali....
    vector<int> arr = {3, 4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            break;
        }
        else if (arr[start] <= arr[mid])
        {
            if (arr[start] <= target && target <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= target && target <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    if (ans == -1)
    {
        cout << target << " not found .\n";
    }
    else
    {
        cout << target << " found at index : " << ans;
    }

    return 0;
}