#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// ye time complexity bhadiya h
int findDup(vector<int> arr)
{
    unordered_set<int> s;
    for (int val : arr)
    {
        if (s.find(val) != s.end())
        {
            return val;
        }
        s.insert(val);
    }
    return -1;
}

// agar q me given ho constand space complexity.......
int slowFastApproach(vector<int> arr)
{
    // kya karenge do pointers lenge aur unko traverse kataenge jo value h array me wo next pointer bnega fir jo wha value h wo..
    int slow = arr[0], fast = arr[0];
    // slow ko +1 se bhadaenge and fast ko +2 se jab we meet karenge end.
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // same step firse but ab same pace se bhadenge to jha meet karenge wo cycle ka staring point hoga to whi duplicated value hogiii.....
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return fast;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 3, 5};
    int ans = findDup(arr);
    cout << "The repeating value is : " << ans << endl;

    int slowFastAns = slowFastApproach(arr);
    cout << "The repeating element with slowFastApproach : " << slowFastAns;
    return 0;
}