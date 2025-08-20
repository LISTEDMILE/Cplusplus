#include <iostream>
#include <vector>
using namespace std;


int SingleElement(vector <int> nums){

    // pehle to same mid element nikalenge fir check krenge condition equal wali but nhi hua to
    // if mid is odd ... see the original array is always gonna be odd.
    // if index of mid is odd then if the element at left is equal to mid one the element is in right side and if the element at right is equal the element is in left
    // if index of mid is even then if the  element at left is equal the element is in the left only same for right;....
    int start = 0;
    int end = nums.size() - 1;
    // special case if array is of length 0;
    if(nums.size() == 1){
        return nums[0];
    }
    while (start <= end){
        int mid = start + (end - start) / 2;

        // special case if mid = 0 ;
        if(mid == 0 && nums[mid] != nums[mid+1]){
            return nums[mid];
        }
        else if(mid == nums.size()-1 && nums[mid] != nums[mid-1]){
            return nums[mid];
        }


        if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
            return nums[mid];
        }
        else if(mid % 2 == 0){
            if(nums[mid] == nums[mid-1]){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        else{
            if(nums[mid] == nums[mid-1]){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
    }
}

int main(){

    vector<int> arr = {1, 1, 2, 3,3,4,4,5,5};
    int ans = SingleElement(arr);

    cout << "Single element : " << ans;

    return 0;
}