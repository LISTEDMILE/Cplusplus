#include <iostream>
#include <vector>
using namespace std;

// STL -> standard template library  has pre implementation of various data structures.....

// Vectors  are similar to arrys but these are dynamic means size is not fixed....
int main(){
    //Syntax initialize..
    vector <int> vec;
    vector<int> vec1 = {1, 2, 3,4,5,6 };
    // size 3 and each place is value 0...
    vector<int> vec2(3, 0);

    cout << vec1[0] << "\n";

    // to iterate -> forEach ...
    // this is not normal for loop it is like js for Each loop it will iterate through each element an ( i is the element itself not index here )....
    for (int i: vec1){
        cout << i << "\t";
    }

    // .size() for no of entries...
    cout << "\nThe size of the vec1 : " << vec.size();

    // end me insert ke liye...
    vec1.push_back(12);
    vec1.push_back(34);

    cout << "\nThe array after push : \n";

    for (int i: vec1){
        cout << i << "\t";
    }

    vec1.pop_back();
    vec1.pop_back();

    cout << "\nThe arry after pop : \n";

    for (int i: vec1){
        cout << i << "\t";
    }

    cout << "\nThe value at front : " << vec1.front();
    cout << "\nThe value at end : " << vec1.back();

    cout << "\nValue at index 2 : " << vec1.at(2);


    //in vector at first only one element array like structure is created after that if included double location is alloted after filling it is doubled like this it goes off in multiple of 2 ....

    // no. of element by .size();
    // capacity by .capacity();
    cout << "\nThe element in vec1 = : " << vec1.size();
    cout << "\nThe capacity of vec1 = : " << vec1.capacity();


    // ---- Single Number Problem
    // return only number which is not repeated in the array there is only one..

    vector<int> prob = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7};
    //see if we exor two no. if they are same return 0 and something exor with 0 is same no. only 
    // we can do it easily but the problem is time constraint.. we have to do it in O(n) time complexity...
    int ans = 0;
    for(int i : prob){
        ans = ans ^ i;
    }
    cout << "\nThe unique element is : " << ans;

    return 0;
}