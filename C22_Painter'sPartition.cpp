#include <iostream>
#include <vector>
using namespace std;

bool isValid(int mid, vector <int>& time, int painters){
    long long sum = 0;
    int count = 1;
    for(int val: time){
        if(val>mid){
            return false;
        }
        else if(sum + val <= mid){
            sum += val;
        }
        else{
            count++;
            sum = val;
            if(count>painters){
                return false;
            }
        }
    }
    return true;
}

int MinTime(vector<int>& time , int painters){
    long long end = 0;
    int start = 0;
    for(int val: time){
        end += val;
        start = max(start, val);
    }

    int mid;
    int ans;
    while(start<=end){
        mid = start + (end - start) / 2;
        if(isValid(mid,time,painters)){
            end = mid - 1;
            ans = mid;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){

    vector <int> WorkTime = {10, 20 ,30 ,40};
    int painters = 2;
    int minTime = MinTime(WorkTime, painters);
    cout << "Minimum time : " << minTime;
    return 0;
}