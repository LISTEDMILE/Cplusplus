#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maj(vector<int> examp)
{
    int freq = 0;
    for (int val : examp)
    {
        freq = 0;
        for (int el : examp)
        {
            if (el == val)
            {
                freq++;
            }
        }
        if (freq > examp.size() / 2)
        {
            return val;
        }
    }
    return -1;
}

int majOp(vector<int> nums)
{
    int freq = 0;
    int ele = nums[0];

    // to sort we can use...
    // starting pointer and end pointer ke through sort ho gya algorith module import karna padega....
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == ele)
        {
            freq++;
        }
        else
        {
            freq = 1;
            ele = nums[i];
        }
        if (freq > nums.size() / 2)
        {
            return ele;
        }
    }
    return -1;
}


int majMVA(vector<int> nums){
    int freq = 0;
    int ans = nums[0];
    for (int val: nums){
        if(freq == 0){
            ans = val;
        }
        if(ans == val){
            freq++;
        }
        else{
            freq--;
        }
       
       
    }

    // if we have to return -1 if not majority element than here we have one more step...
    int count;
    for (int val : nums){
        if(val == ans ){
            count++;
        }
    }
    if(count>nums.size()/2){
        return ans;
    }    
    return -1;

}


int main()
{

    // print element jo array me aadhe se bhi jyada bar aaya ho...
    // always majority element present...

    vector<int> vec = {1, 6, 2, 5, 6, 6, 6, 6, 2, 6, 5};
    int ans = maj(vec);
    cout << "The majority element is : " << ans;

    // in Majority element problem the array is always sorted...

    int ansOp = majOp(vec);
    cout << "\n\nThe majority element is : " << ansOp;

    // One more optimised algorithm is there --> Moore's Voting Algorithm

    int ansMVA = majMVA(vec);
    cout << "\n\nThe majority element is : " << ansMVA;
    return 0;
}