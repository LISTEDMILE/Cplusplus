#include <iostream>
#include <vector>
using namespace std;


/// in this the array first increase than decrease we have to find the peak element.....

int Peak(vector <int > arr){
    int start = 0;
    int end = arr.size() - 1;
     while (start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            return mid;
        }
        else if(arr[mid] > arr[mid-1]){

            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {1, 2, 4, 6, 9, 5, 3, 0};
    int ans = Peak(arr);

    cout << "Peak element : " << arr[ans] << " is at inxex : " << ans;

    return 0;
}