#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(pair <int,int>p1, pair <int,int>p2){
if(p1.second < p2.second)
    return true;
    if(p1.second >p2.second) return false;
    if(p1.first <p2.first)
        return true;
    else
        return false;
}

int main(){

    int arr[5] = {2, 5, 2, 5, 6};
    sort(arr, arr + 5);

    cout << "\n\n";

    for(int val: arr){
        cout << val << "\t";
    }

    vector<int> vec = {2, 5, 2, 5, 6};
    sort(vec.begin(), vec.end());

    
    cout << "\n\n";

    for(int val: vec){
        cout << val << "\t";
    }


    vector<int> vecDec = {2, 5, 2, 5, 6};
    
    sort(vecDec.begin(), vecDec.end(),greater<int>());

    
    cout << "\n\n";
    
    for(int val: vecDec){
        cout << val << "\t";
    }


    vector<pair<int,int>> vecPair = {{2,3} , {3,5} ,{6,3} ,{3,6}};
    sort(vecPair.begin(), vecPair.end());

    
    cout << "\n\n";
    
    for(auto p: vecPair){
        cout << p.first << " : " << p.second << "\t";
    }

    // we can also use custom comparator.....
    vector<pair<int,int>> vecPairCustom = {{2,3} , {3,5} ,{6,3} ,{3,6}};
    sort(vecPairCustom.begin(), vecPairCustom.end(),comparator);

    
    cout << "\n\n";
    
    for(auto p: vecPairCustom){
        cout << p.first << " : " << p.second << "\t";
    }

     cout  << "\nFind 5 in vec : " << binary_search(vec.begin(), vec.end(),5);

    reverse(vecPair.begin(), vecPair.begin() + 2);
    cout << "\n\n";
    
    for(auto p: vecPair){
        cout << p.first << " : " << p.second << "\t";
    }

    reverse(vec.begin(), vec.end());
    cout << "\n\n";

    
    for(int val: vec){
        cout << val << "\t";
    }

    cout << "\nMax : " << *max_element(vec.begin(), vec.end());
    cout << "\nMin : " << *min_element(vec.begin(), vec.end());

   

    return 0;
}