#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMinPathByRecursion(vector<int> &arr,int idx){  //O(n2) , space-O(n)
    if(idx == 0){
        return 0;
    }
    int next = findMinPathByRecursion(arr, idx - 1) + abs(arr[idx]- arr[idx-1]);
    int nextNext = INT16_MAX;
    if(idx!=1){
        nextNext = findMinPathByRecursion(arr, idx - 2) + abs(arr[idx]- arr[idx-2]);
    }

    return min(next, nextNext);
}

int findMinPathOptimalMemoization(vector<int>& arr,int idx,vector<int> & p){  //O(n) , space-O(n+n)
    if(idx == 0){
        return 0;
    }

    if(p[idx]!=-1){
        return p[idx];
    }

    int next = findMinPathOptimalMemoization(arr, idx - 1,p) + abs(arr[idx]- arr[idx-1]);
    int nextNext = INT16_MAX;
    if(idx!=1){
        nextNext = findMinPathOptimalMemoization(arr, idx - 2,p) + abs(arr[idx]- arr[idx-2]);
    }

    return p[idx] = min(next, nextNext);
}


int findMinPathOptimalTabular(vector<int>& arr,int n,vector<int> & p){ //O(n) , space-O(n)

    p[0] = 0;
    p[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i < n; i++){
        p[i] = min((abs(arr[i] - arr[i - 1]) + p[i - 1]), (abs(arr[i] - arr[i - 2]) + p[i - 2]));
    }
    return p[n-1];
}

int findMinPathMostOptimal(vector<int>& arr,int n){ //O(n) , space-O(1)

    if(n==1){
        return arr[0];
    }
    if(n==2){
        return abs(arr[1] - arr[0]);
    }
    int prevPrev = 0;
    int prev = abs(arr[1] - arr[0]);
    int curr = INT16_MIN;
    for (int i = 2; i < n; i++){
      curr = min((abs(arr[i] - arr[i - 1]) + prev), (abs(arr[i] - arr[i - 2]) + prevPrev));
       prevPrev = prev;
       prev = curr;
    }
    return curr;
}

int main()
{
    vector<int> arr =
        {1, 45, 4,3,23,50,60,100,9,2};

    cout << "Minimum distance (Recursion) : " << findMinPathByRecursion(arr, arr.size()-1);

    vector<int> p(arr.size(), -1);

    cout << "\nMinimum distance (Memoization) : " << findMinPathOptimalMemoization(arr, arr.size()-1,p);

    fill(p.begin(), p.end(), -1);

    cout << "\nMinimum distance (Tabulation) : " << findMinPathOptimalTabular(arr, arr.size(),p);

    cout << "\nMinimum distance (Most Optimal) : " << findMinPathMostOptimal(arr, arr.size());


    return 0;
}